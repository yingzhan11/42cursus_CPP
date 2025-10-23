#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

/**
 * calculation part
 */
void RPN::calculation(const std::string &input)
{
	//parse input
	if (input.empty())
		throw std::runtime_error("Error: Empty input");

	std::istringstream iss(input);
	std::string arg;
	const std::string operators = "+-*/";

	while (iss >> arg) //skip space auto
	{
		if (arg.size() == 1 && std::isdigit(arg[0]))
			_stack.push(arg[0] - '0');
		else if (arg.size() == 1 && operators.find(arg[0]) != std::string::npos)
			_performOperation(arg[0]);
		else
			throw std::runtime_error("Error: invalid arg '" + arg + "'.");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression.");

	std::cout << "Result:" << _stack.top() << std::endl;

	//calculate
}

void RPN::_performOperation(char operat)
{
	double n1;
	double n2;
	double result;

	if (_stack.size() < 2)
		throw std::runtime_error("Error: too less numbers");
	
	n1 = _stack.top();
	_stack.pop();
	n2 = _stack.top();
	_stack.pop();

	switch (operat)
	{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			if (n2 == 0)
				throw std::runtime_error("Error: division by zero");
			result = n1 / n2;
			break;
		default:
			break;
	}

	_stack.push(result);
}

//void RPN::_parseInput(const std::string &input)
//{
//	if (input.empty())
//		throw std::runtime_error("Error: Empty input");

//	std::istringstream iss(input);
//	std::string arg;
//	const std::string operators = "+-*/";


//}