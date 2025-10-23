#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong format. Should be [./RPN \"mathematical expression\"]" << std::endl;
		return 1;
	}

	RPN rpn;

	try {
		rpn.calculation(av[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}