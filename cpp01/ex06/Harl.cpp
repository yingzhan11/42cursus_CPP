/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:07 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 15:12:08 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";
	this->_level[4] = "OTHER";

	_harlFunctions[0] = &Harl::_debug;
	_harlFunctions[1] = &Harl::_info;
	_harlFunctions[2] = &Harl::_warning;
	_harlFunctions[3] = &Harl::_error;
	_harlFunctions[4] = &Harl::_other;
}

Harl::~Harl(void){}

void	Harl::complain( std::string level )
{
	int	i = 0;

	while (i < 4 && level != this->_level[i])
		i++;
	int	j = i;
	switch (i)
	{
		case 0:
			while (j < 4)
				(this->*_harlFunctions[j++])();
			break;
		case 1:
			while (j < 4)
				(this->*_harlFunctions[j++])();
			break;
		case 2:
			while (j < 4)
				(this->*_harlFunctions[j++])();
			break;
		case 3:
			while (j < 4)
				(this->*_harlFunctions[j++])();
			break;
		default:
			(this->*_harlFunctions[j])();
			break;
	}
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]\n"
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]\n"
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::_other(void)
{
	std::cout << "[ OTHER ]\n" << "I need HOLIDAY!!!" << std::endl;
}
