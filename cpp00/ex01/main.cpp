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
		std::cout << "Enter a command(ADD/SEARCH/EXIT): ";
		if (!std::getline(std::cin, input))
			std::cout << "Fail to getline/Signal quit\n";
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact(phoneBook);
		else if (input == "EXIT")
			break;
		else
			std::cout << "Command not found\n";
	}
	return 0;

}