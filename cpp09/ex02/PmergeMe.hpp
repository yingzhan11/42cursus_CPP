#pragma once

#include <vector>
#include <list>
#include <chrono>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::list<int> _list;

		std::chrono::microseconds _vecTime;
		//std::chrono::microseconds _listTime;

		void _vecSort(std::vector<int> &vec);

		bool _isDigitStr(std::string str);
		void _printVec();
		void _printList();
		std::vector<std::size_t> _getInsertOrder(std::size_t size);

	public:
		PmergeMe() = delete;
		PmergeMe(const PmergeMe& other) = delete;
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other) = delete;

		PmergeMe(size_t ac, char **av);
};