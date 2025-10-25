#include "PmergeMe.hpp"

int PmergeMe::_recDepth = 0;

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(size_t ac, char **av)
{
	//set a max TODO
	// if (ac > 5000)
	// 	throw std::runtime_error("Error: too many numbers");
	for (size_t i = 0; i < ac; i++)
	{
		std::string nbrStr(av[i]);
		int nbr;

		//check if the input is valid, only nbrs
		if (!_isDigitStr(nbrStr))
			throw std::runtime_error("Error: input should be only numbers");
		//convert input string to int
		try {
			nbr = std::stoi(nbrStr);
		} catch(const std::exception& e) {
			throw std::runtime_error("Error: stoi fail");
		}
		//put nbrs into container
		_vec.push_back(nbr);
		_list.push_back(nbr);
	}

	/** Vector */
	#ifdef DEBUG
	std::cout << "Sorting by std::vector<int>: \n";
	#endif

	auto startTime = std::chrono::high_resolution_clock::now(); //get start time
	//sorting
	_vecSort(_vec);
	auto endTime = std::chrono::high_resolution_clock::now(); //get end time
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	
	/** List */
	#ifdef DEBUG
	std::cout << "Sorting by std::list<int>: \n";
	#endif
	
	startTime = std::chrono::high_resolution_clock::now();
	_listSort(_list);
	endTime = std::chrono::high_resolution_clock::now();
	_listTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	
	if (!std::is_sorted(_vec.begin(), _vec.end()))
    	throw std::runtime_error("Vector not sorted correctly!");
	if (!std::is_sorted(_list.begin(), _list.end()))
    	throw std::runtime_error("List not sorted correctly!");
	_printResult(ac, av);
}

void PmergeMe::_vecSort(std::vector<int> &vec)
{
	const std::size_t size = vec.size();
	if (size < 2) //when only 1 nbr in the container, it is the end of recursion, and go back
		return;

	/** Pairing and sort Max*/
	//1-pair two numbers, and each pair is sorted as [small_nbr, big_nbr]
	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(size / 2); //pre allocates for pairs, and avoid reallocation in emplace_back()
	for (std::size_t i = 0; i + 1 < size; i += 2) {
		int n1 = vec[i];
		int n2 = vec[i + 1];
		if (n1 < n2)
			pairs.emplace_back(n1, n2);
		else
			pairs.emplace_back(n2, n1);
	}

	//2-put nbr a and b into two container
	std::vector<int> A; // for bigger nbrs in its pair
	A.reserve((size + 1) / 2); // prepare extra space for odd amount of nbrs
	std::vector<int> B; // for smaller nbrs
	B.reserve(size / 2);
	for (const auto& p : pairs) {
		A.push_back(p.second);
		B.push_back(p.first);
	}
	if (size % 2 == 1)
		A.push_back(_vec.back()); //if nbrs' amount is an odd nbr, put the last nbr into A container

	#ifdef DEBUG
	_debugContainers(true, A, B);
    #endif

	//3-Recursion to sort bigger nbrs
	_recDepth++;
	_vecSort(A);
	_recDepth--;
	
	/** Insert Min nbrs in B to A*/
	const std::vector<std::size_t> order = _getInsertOrder(B.size());

	#ifdef DEBUG
	_debugContainers(false, A, B);
	#endif

	for (std::size_t idx : order) {
		if (idx < B.size())
			_vectorBinaryInsert(A, B[idx]);
	}
	vec.swap(A);
}

void PmergeMe::_listSort(std::list<int> &list)
{
	const std::size_t size = list.size();
	if (size < 2)
		return;

	/** Pairing and sort Max*/
	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(size / 2);
	auto it = list.begin(); //list need to use iterator
	while (it != list.end()) {
		int n1 = *it;
		auto itNext = std::next(it);
		if (itNext == list.end())
			break;
		int n2 = *itNext;
		if (n1 < n2)
			pairs.emplace_back(n1, n2);
		else
			pairs.emplace_back(n2, n1);
		std::advance(it, 2);
	}

	std::list<int> A;
	std::list<int> B;
	for (const auto& p : pairs) {
		A.push_back(p.second);
		B.push_back(p.first);
	}
	if (size % 2 == 1)
		A.push_back(_list.back());

	#ifdef DEBUG
	_debugContainers(true, A, B);
    #endif
	
	_recDepth++;
	_listSort(A);
	_recDepth--;

	/** Insert Min nbrs in B to A*/
	const std::vector<std::size_t> order = _getInsertOrder(B.size());

	#ifdef DEBUG
	_debugContainers(false, A, B);
	#endif

	for (std::size_t idx : order) {
		if (idx < B.size()) {
			auto itB = B.begin();
			std::advance(itB, idx); //find the it of current idx
			int value = *itB;
			_listBinaryInsert(A, value);
		}
	}
	list.swap(A);
}

/**
 * Generator Insert Order based on Jacobsthal number
 * 
 * Jacobsthal number[0,1,1,3,5,11...] : nbr3=nbr2+nbr1*2
 * 
 * In the Ford–Johnson (merge-insertion) algorithm, it starts from 3, and use a zig-zag order,
 * which means: insert nbr3 first, then nbr2, nbr1(the first one, no more nbr before nbr1, so move to
 * the next JacobNbr is 5) ---> nbr5, nbr4(next is the previous JacobNbr 3, continuing move to next JacobNbr 11)
 * ---> nbr11, nbr10, nbr9, nbr8, nbr7, nbr6 ---> next JacobNbr...
 * The order is: [3,2,1,5,4,11,10,9,8,7,6,...]
 * 
 * Need to notice, here is the mathmetical nbr, so when it is used in the code index, need to -1.
 * The index is: [2,1,0,4,3,10,9,8,7,6,5,...]
 */
std::vector<std::size_t> PmergeMe::_getInsertOrder(std::size_t size)
{
	std::vector<std::size_t> order;
	order.reserve(size);
	if (size == 0)
		return order;

	std::vector<std::size_t> jacob = _getJacobsthalNbr(size);
	std::vector<std::size_t> jacobIdx;
	std::vector<bool> pushed(size, false); //record which idx already push into order

	for (std::size_t j : jacob)
		jacobIdx.push_back(j - 1);
	for (std::size_t j : jacobIdx)
	{
		//push Jacob index
		if (j < size && !pushed[j]) {
			order.push_back(j);
			pushed[j] = true;
		}
		//push all idexs from current JacobIdx to previous JacobIdx, in decement order
		for (std::size_t i = j; i >= 1; i--) {
			if (i - 1 < size && !pushed[i - 1]) {
				order.push_back(i - 1);
				pushed[i - 1] = true;
			}
		}
	}
	//push all rest idxs, if there is any
	for (std::size_t i = 0; i < size; i++) {
		if (!pushed[i])
			order.push_back(i);
	}

	#ifdef DEBUG
	_debugJacob(jacob, jacobIdx, order);
	#endif
	
	return order;
}

//Func to generate Jacobsthal numbers
std::vector<std::size_t> PmergeMe::_getJacobsthalNbr(std::size_t size)
{
    std::vector<std::size_t> j;
    std::size_t j0 = 1;
	std::size_t j1 = 3;

    while (j1 < size) {
		j.push_back(j1);
        std::size_t j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    return j;
}

/**
 * Binary Insert
 */
void PmergeMe::_vectorBinaryInsert(std::vector<int> &vec, const int &value)
{
	std::size_t left = 0;
	std::size_t right = vec.size(); //set the range

	while (left < right) {
		std::size_t mid = left + (right - left) / 2;
		if (value < vec[mid])
			right = mid; //reset the range to the part before mid
		else
			left  = mid + 1; //reset the range to the part after mid
	}
	vec.insert(vec.begin() + left, value);
}

void PmergeMe::_listBinaryInsert(std::list<int> &lst, const int &value)
{
    auto left = lst.begin();
    auto right = lst.end();
    std::size_t len = lst.size();

    while (len > 0) {
        auto mid = left;
        std::advance(mid, len / 2); // move to middle
        if (value < *mid) {
            right = mid;
            len /= 2;
        } else {
            left = ++mid;
            len = (len - 1) / 2;
        }
    }
    lst.insert(left, value);
}

/**
 * Helpers & Debug
 */
bool PmergeMe::_isDigitStr(std::string str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void PmergeMe::_printResult(size_t ac, char **av)
{
	std::cout << "Before sorted: ";
	for (size_t i = 0; i < ac; ++i) {
        std::cout << av[i] << " ";
    }
	std::cout << "\nAfter sorted: ";
	_printContainer(_vec);
	std::cout << "\nTime to sort " << _vec.size() << " numbers with std::vector use: " << _vecTime.count() << " us\n";
	std::cout << "Time to sort " << _list.size() << " numbers with std::list use: " << _listTime.count() << "us\n";
}

void PmergeMe::_debugJacob(const std::vector<size_t>& jacob, const std::vector<size_t>& idx, const std::vector<size_t>& order)
{
	std::cout << COLOR_RETURN << std::string(_recDepth * 8, ' ') << "<<< Recursion Depth: " << _recDepth << "\n";
	std::cout << COLOR_INFO << std::string(_recDepth * 8, ' ') << "Jacobsthal nbr: [ ";
	_printContainer(jacob);
    std::cout << "]  Jacobsthal index: [ ";
	_printContainer(idx);
    std::cout << "]\n";
	std::cout << std::string(_recDepth * 8, ' ') << "Insert index: [ ";
	_printContainer(order);
	std::cout << "]\n" << COLOR_RESET;
}