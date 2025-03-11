#include "PhoneBook.hpp"

//constructor
PhoneBook::PhoneBook()
	: _totalContacts(0), _nextIndex(0){}

//public functions
void PhoneBook::addContact()
{
	std::string	input;
	Contact		newContact;

	// get 5 feild for a contact
	for (int i = 0; i < 5; i++)
	{
		// tell user what to enter
		newContact.fieldPrompt(i); //TODO
		//get user input
		if (!std::getline(std::cin, input))
			std::cout << "Fail to getline/Signal quit\n";
		//check empty field and invalid input [TODO]
		if (input.empty() || _isOnlySpace(input))
		{
			std::cout << "The contact field cannot be empty, please try again\n";
			i--;
			continue;
		}
		// add to a contact field
		else
			newContact.addField(i, input); //TODO
	}
	// add the new contact to contactList

}

void PhoneBook::searchContact(PhoneBook &phoneBook)
{

}

//private functions
bool	_isOnlySpace(const std::string &str)
{
	for (char c : str) //????
	{
		if (!std::isspace(c))
			return false;
	}
	return true;
}