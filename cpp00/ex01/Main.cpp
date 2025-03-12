#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	std::string	input;
	PhoneBook	phoneBook;

	(void)argv;
	if (argc != 1)
	{
		std::cout << "Invalid cmd, please run [./phoneBook]";
		return 1;
	}
	while (1)
	{
		std::cout << "\033[32m" << "Enter a command(ADD/SEARCH/EXIT): " << "\033[0m";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\033[31m" << "Fail to getline/Signal quit\n" << "\033[0m";
			return 1;
		}
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "\033[33m" << "Command not found, please enter a correct cmd\n" << "\033[0m";
	}
	return 0;

}