#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Wrong format. Should be [./PmergeMe n1 n2 n3 n4 ...]" << std::endl;
		return 1;
	}

	try {
		av++;
		PmergeMe merge(ac - 1, av);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}