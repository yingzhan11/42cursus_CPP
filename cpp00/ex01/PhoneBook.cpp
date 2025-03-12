#include "PhoneBook.hpp"

//constructor
PhoneBook::PhoneBook()
	: _totalContacts(0), _nextIndex(0){}


//public functions
void	PhoneBook::addContact()
{
	std::string	input;
	Contact		newContact;

	// get 5 feild for a contact
	for (int i = 0; i < 5; i++)
	{
		// tell user what to enter
		newContact.fieldPrompt(i);
		//get user input
		if (!std::getline(std::cin, input))
		{
			std::cout << "\033[31m" << "Fail to getline/Signal quit\n" << "\033[0m";
			exit(1);
		}
		//check empty field and invalid input
		if (newContact.isEmptyInput(input) || (i == 3 && !newContact.isValidPhoneNumber(input)))
		{
			i--;
			continue;
		}
		// add to a contact field
		else
			newContact.addField(i, input);
	}
	// add the new contact to contactList
	contactList[_nextIndex] = newContact;
	if (_totalContacts < 8)
		_totalContacts++;
	_nextIndex++;
	if (_nextIndex == 8)
		_nextIndex = 0;
	//nextIndex = (nextIndex + 1) % 8;

}

void PhoneBook::searchContact()
{
	int index = -1;

	if (_totalContacts == 0)
	{
		std::cout << "\033[33m" << "The PhoneBook is empty.\n" << "\033[0m";
		return ;
	}
	//display the whole phone book
	_displayPhoneBook();
	//ask fot index
	while (index == -1)
		index = _getIndex();
	//show full info
	if (index > _totalContacts)
		std::cout << "\033[33m" << "Cannot found this index in the PhoneBook.\n" << "\033[0m";
	else
		contactList[index].printContact();
}

//private functions
void	PhoneBook::_displayPhoneBook()
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "FirstName" << "|"
				<< std::setw(10) << "LastName" << "|"
				<< std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < _totalContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << _displayFeild(contactList[i].getName(1)) << "|"
				<< std::setw(10) << _displayFeild(contactList[i].getName(2)) << "|"
				<< std::setw(10) << _displayFeild(contactList[i].getName(3)) << std::endl;
	}
}

std::string	PhoneBook::_displayFeild(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	PhoneBook::_getIndex()
{
	std::string	input;
	int			index;

	std::cout << "\033[34m" << "Enter the index number: " << "\033[0m";
	if (!std::getline(std::cin, input))
	{
		std::cout << "\033[31m" << "Fail to getline/Signal quit\n" << "\033[0m";
		exit(1);
	}
	if (input.length() < 2)
	{
		if (!std::isdigit(input[0]))
		{
			std::cout << "\033[33m" << "Invalid input. Please enter a number.\n" << "\033[0m";
			return (-1);
		}
		std::istringstream	inputNbr(input);
		inputNbr >> index;
		return (index);
	}
	else
		std::cout << "\033[33m" << "The input is too long. Please enter only one number\n" << "\033[0m";
	return (-1);
}
