#pragma once

#include <vector>
#include <list>
#include <chrono>
#include <string>
#include <iostream>
#include <algorithm>

#define COLOR_ENTER "\033[32m"  // GREEN: enter recursion
#define COLOR_RETURN "\033[33m" // YELLOW: return
#define COLOR_INFO "\033[36m" //CYAN: Jacob info
#define COLOR_RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::chrono::microseconds _vecTime;

		std::list<int> _list;
		std::chrono::microseconds _listTime;

		void _vecSort(std::vector<int> &vec);
		void _vectorBinaryInsert(std::vector<int> &vec, const int &value);
		void _listSort(std::list<int> &list);
		void _listBinaryInsert(std::list<int> &lst, const int &value);

		bool _isDigitStr(std::string str);
		std::vector<std::size_t> _getInsertOrder(std::size_t size);
		std::vector<std::size_t> _getJacobsthalNbr(std::size_t limit);

	public:
		PmergeMe() = delete;
		PmergeMe(const PmergeMe& other) = delete;
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other) = delete;
		PmergeMe(size_t ac, char **av);

	//for debug
	private:
		static int _recDepth;

		void _printResult(size_t ac, char **av);
		void _debugJacob(const std::vector<size_t>& jacob, const std::vector<size_t>& idx, const std::vector<size_t>& order);

		template <typename Container>
		void _debugContainers(bool recur, const Container& A, const Container& B)
		{
			if (recur) {
				std::cout << COLOR_ENTER;
				std::cout << std::string(_recDepth * 8, ' ') << ">>> Recursion Depth: " << _recDepth << "\n";
			}
			else {
				std::cout << COLOR_RETURN;
				std::cout << std::string(_recDepth * 8, ' ') << "<<< Recursion Depth: " << _recDepth << "\n";
			}
			std::cout << std::string(_recDepth * 8, ' ') << "Container A has " << A.size() << " nbrs: ";
			_printContainer(A);
			std::cout << "\n" << std::string(_recDepth * 8, ' ') << "Container B has " << B.size() << " nbrs: ";
			_printContainer(B);
			if (recur)
				std::cout << "\n";
			std::cout << "\n" << COLOR_RESET;
		}

		template <typename Container>
		void _printContainer(const Container& c) {
			auto it = c.begin();
			if (it != c.end()) {
				std::cout << *it;
				++it;
			}
			for (; it != c.end(); ++it) {
				std::cout << " " << *it;
			}
		}
};