/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:41:22 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/17 14:41:25 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * Constructor
 */
Contact::Contact()
	: _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret(""){}

/**
 * Public functions
 */
// Display the prompt to user
void	Contact::fieldPrompt(int i)
{
	std::cout << std::left << "\033[34m";
	switch (i)
	{
		case FIRSTNAME:
			std::cout << std::setw(16) << "First Name: ";
			break;
		case LASTNAME:
			std::cout << std::setw(16) << "Last Name: ";
			break;
		case NICKNAME:
			std::cout << std::setw(16) << "Nick Name: ";
			break;
		case PHONENUMBER:
			std::cout << std::setw(16) << "Phone Number: ";
			break;
		case DARKESTSECRET:
			std::cout << std::setw(16) << "Darkest Secret: ";
			break;
		default:
			std::cout << "Invalid field.\n";
			break;
	}
	std::cout << std::right << "\033[0m";
}

// Check the user input of contact is valid or not
bool	Contact::isEmptyInput(const std::string &str)
{
	bool valid = true;

	if (!str.empty())
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if (!std::isspace(c))
			{
				valid = false;
				break;
			}
		}
	}
	if (valid)
		std::cout << "\033[33m" << "The contact field cannot be empty, please try again\n" << "\033[0m";
	return valid;
}


// Check the phoneNumber feild validation: only '0-9' and a '+' at the beginning
bool	Contact::isValidPhoneNumber(const std::string &phoneNumber)
{
    int		plusCount = 0;
	int		nbrCount = 0;
	bool	valid = true;

    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        if (phoneNumber[i] == '+')
        {
            if (i != 0)
                valid = false;
			else
	            plusCount++;
        }
        else if (!std::isdigit(phoneNumber[i]))
            valid = false;
		else
			nbrCount++;
		if (valid == false)
			break;
    }
	if (nbrCount < 1 || plusCount > 1)
		valid = false;
	if (valid == false)
		std::cout << "\033[33m" << "The phone number should only have + and numbers, please try again\n" << "\033[0m";
    return valid;
}

void	Contact::addField(int i, const std::string &str)
{
	switch (i)
	{
		case FIRSTNAME:
			_firstName = str;
			break;
		case LASTNAME:
			_lastName = str;
			break;
		case NICKNAME:
			_nickName = str;
			break;
		case PHONENUMBER:
			_phoneNumber = str;
			break;
		case DARKESTSECRET:
			_darkestSecret = str;
			break;
		default:
			std::cout << "\033[33m" << "Invalid field to add.\n" << "\033[0m";
			break;
	}
}

std::string	Contact::getName(int i)
{
	if (i == FIRSTNAME)
		return (_firstName);
	else if (i == LASTNAME)
		return (_lastName);
	else
		return (_nickName);
}

void	Contact::printContact()
{
	std::cout << std::left;
	std::cout << std::setw(15) << "FirstName: " << _firstName << std::endl;
	std::cout << std::setw(15) << "LastName: " << _lastName << std::endl;
	std::cout << std::setw(15) << "Nickname: " << _nickName << std::endl;
	std::cout << std::setw(15) << "PhoneNumber: " << _phoneNumber << std::endl;
	std::cout << std::setw(15) << "DarkestSecret: " << _darkestSecret << std::endl;
	std::cout << std::right;
}

