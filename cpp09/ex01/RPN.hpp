#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
	private:
		std::stack<double> _stack;

		//void _parseInput(const std::string &input);
		void _performOperation(char operat);

	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN &operator=(const RPN &other);

		void calculation(const std::string &input);
		

};