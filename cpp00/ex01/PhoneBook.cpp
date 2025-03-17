/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:41:56 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/17 14:41:58 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * Constructor
 */
PhoneBook::PhoneBook()
	: _totalContacts(0), _nextIndex(0){}

/**
 * Public functions
 */
// Add contacts to phoneBook
void	PhoneBook::addContacts()
{
	std::string	input;
	Contact		newContact;

	// Get 5 feilds for a contact
	for (int i = 0; i < 5; i++)
	{
		// Tell user what to enter and get user input
		newContact.fieldPrompt(i);
		if (!std::getline(std::cin, input))
		{
			std::cout << "\033[31m" << "Fail to getline/Signal quit\n" << "\033[0m";
			exit(1);
		}
		// Check empty field and invalid input
		if (newContact.isEmptyInput(input) || (i == 3 && !newContact.isValidPhoneNumber(input)))
		{
			i--;
			continue;
		}
		// Add to a field
		else
			newContact.addField(i, input);
	}
	// Add the new contact to contactList
	contactList[_nextIndex] = newContact;
	if (_totalContacts < 8)
		_totalContacts++;
	_nextIndex = (_nextIndex + 1) % 8;
}

// Search contacts and diaplay one from phoneBook
void PhoneBook::searchContacts()
{
	int index = -1;

	if (_totalContacts == 0)
	{
		std::cout << "\033[33m" << "The PhoneBook is empty.\n" << "\033[0m";
		return ;
	}
	// Display the whole phone book
	_displayPhoneBook();
	// Get the index user enter and show the contact info
	while (index == -1)
		index = _getIndex();
	contactList[index].printContact();
}

/**
 * Private functions
 */
// Display the whole phoneBook
void	PhoneBook::_displayPhoneBook()
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "FirstName" << "|"
				<< std::setw(10) << "LastName" << "|"
				<< std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < _totalContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << _displayFeild(contactList[i].getName(0)) << "|"
				<< std::setw(10) << _displayFeild(contactList[i].getName(1)) << "|"
				<< std::setw(10) << _displayFeild(contactList[i].getName(2)) << std::endl;
	}
}

// Limit the long feild to 10
std::string	PhoneBook::_displayFeild(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

// Get the user input and return the valid index
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
		// Check the validation of input index
		if (!std::isdigit(input[0]))
		{
			std::cout << "\033[33m" << "Invalid input. Please enter a number.\n" << "\033[0m";
			return (-1);
		}
		// Get index
		std::istringstream	inputNbr(input);
		inputNbr >> index;
		if (index >= _totalContacts)
		{
			std::cout << "\033[33m" << "Cannot found this index in the PhoneBook. Please try again.\n" << "\033[0m";
			return (-1);
		}
		return (index);
	}
	else
		std::cout << "\033[33m" << "The input is too long. Please enter only ONE number.\n" << "\033[0m";
	return (-1);
}
