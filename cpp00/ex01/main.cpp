/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:41:40 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 11:22:17 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	std::string	input;
	PhoneBook	phoneBook;

	(void)argv;
	if (argc != 1)
	{
		std::cout << "Invalid cmd, please run [./phoneBook]\n";
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
			phoneBook.addContacts();
		else if (input == "SEARCH")
			phoneBook.searchContacts();
		else if (input == "EXIT")
			break;
		else
			std::cout << "\033[33m" << "Command not found, please enter a correct cmd\n" << "\033[0m";
	}
	return 0;
}
