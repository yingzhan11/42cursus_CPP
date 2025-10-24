#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(size_t ac, char **av)
{
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

	//print unsorted nbrs
	std::cout << "Before sorted:\t";
	_printVec();

	//1-Vector
	//get start time
	auto startTime = std::chrono::high_resolution_clock::now();
	//sorting
	_vecSort(_vec);
	//get end time
	auto endTime = std::chrono::high_resolution_clock::now();
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

	//2-List
	//get start time
	//startTime = std::chrono::high_resolution_clock::now();
	//sorting
	//_vecList(_vec);
	//get end time
	//endTime = std::chrono::high_resolution_clock::now();
	//_listTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	
	//check sorted??

	//print sorted nbrs
	std::cout << "After sorted:\t";
	_printVec();

	//print time
	std::cout << "Time to sort " << _vec.size() << " numbers with std::vector use: " << _vecTime.count() << " us\n";
	//std::cout << "Time to sort " << _list.size() << " numbers with std::list use: " << _listTime.count() << "us\n";
}

template <typename Seq>
void _binaryInsert(Seq& a, const int value) {

    std::size_t left = 0, right = a.size();
    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        if (value < a[mid])
            right = mid;
        else
            left  = mid + 1;
    }
    a.insert(a.begin() + static_cast<std::ptrdiff_t>(left), value);
}

void PmergeMe::_vecSort(std::vector<int> &container)
{
	const std::size_t size = container.size();

	//when only 1 nbr in the container, it is the end of recursion, and go back
	if (size < 2)
		return;

	//#ifdef DEBUG
    //std::cout << "\n=== sortVector called with ";
    //for (int v : container) std::cout << v << ' ';
    //std::cout << "===\n";
    //#endif
	
	/** Pairing and sort Max*/
	//1-pair two numbers, and each pair is sorted as [small_nbr, big_nbr]
	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(size / 2); //pre allocates for pairs, and avoid reallocation in emplace_back()
	for (std::size_t i = 0; i + 1 < size; i += 2)
	{
		int n1 = container[i];
		int n2 = container[i + 1];
		if (n1 < n2)
			pairs.emplace_back(n1, n2);
		else
			pairs.emplace_back(n2, n1);
	}

	//2-put a and b into two container
	std::vector<int> A; // for bigger nbrs in its pair
	A.reserve((size + 1) / 2); // prepare extra space for odd amount of nbrs
	std::vector<int> B; // for smaller nbrs
	B.reserve(size / 2);
	for (const auto& p : pairs)
	{
		A.push_back(p.second);
		B.push_back(p.first);
	}
	if (size % 2 == 1)
		A.push_back(_vec.back()); //if nbrs' amount is an odd nbr, put the last nbr into A container

	//3-Recursion to sort bigger nbrs
	_vecSort(A);

	/** Insert Min */
	const std::vector<std::size_t> order = _getInsertOrder(B.size());
	//std::cout << "order: ";
	for (std::size_t idx : order)
	{

		//std::cout << idx << " ";
		if (idx < B.size())
			_binaryInsert(A, B[idx]);
	}
	//std::cout << std::endl;

	container.swap(A);
}

//as the book the first Jacobsthal you need is 3
std::vector<std::size_t> _getJacobsthalNbr(std::size_t limit)
{
    std::vector<std::size_t> j;
    std::size_t j0 = 1;
	std::size_t j1 = 3;

    while (j1 < limit)
	{
		j.push_back(j1);
        std::size_t jn = j1 + 2 * j0;
        j0 = j1;
        j1 = jn;
    }
    return j;
}

std::vector<std::size_t> PmergeMe::_getInsertOrder(std::size_t size)
{
	std::vector<std::size_t> order;
	order.reserve(size);


	if (size == 0)
		return order;

	std::vector<std::size_t> jacob = _getJacobsthalNbr(size); // [1,3,5,11,21,43,85,171,...]
	std::vector<bool> used(size, false); //
	
	std::vector<std::size_t> jacobIdx;

	//std::cout << "jacob: ";
	//for (std::size_t j : jacob)
	//{
	//	std::cout << j << " ";
	//}
	//std::cout << std::endl;

	for (std::size_t j : jacob)
	{
		jacobIdx.push_back(j - 1);
	}

	//std::cout << "jacobIdx: ";
	//for (std::size_t j : jacobIdx)
	//{
	//	std::cout << j << " ";
	//}
	//std::cout << std::endl;

	for (std::size_t j : jacobIdx)
	{
		//push Jacob nbr
		if (j < size && !used[j])
		{
			order.push_back(j);
			used[j] = true;
		}
		//push nbrs from current Jacob nbr to previous Jacob nbr, decement order
		for (std::size_t i = j; i >= 1; --i)
		{
			if (i - 1 < size && !used[i - 1])
			{
				order.push_back(i - 1);
				used[i - 1] = true;
			}
		}
	}

	//2-put reminder nbr into order: [1,3,5,0,2,4]
	for (std::size_t i = 0; i < size; ++i)
	{
		if (!used[i])
		{
			//std::cout << "reminder: " << i;
			order.push_back(i);
		}
	}

	return order;
}


/**
 * helper func
 */
bool PmergeMe::_isDigitStr(std::string str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void PmergeMe::_printVec()
{
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << _vec[i];
	}
	std::cout << std::endl;
}

//not used now
void PmergeMe::_printList()
{
	for (size_t i = 0; i < _list.size(); i++)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << *(std::next(_list.begin(), i));
	}
	std::cout << std::endl;
}