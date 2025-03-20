/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:31:49 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 14:31:51 by yzhan            ###   ########.fr       */
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
	std::cout << this->_level[i] << ": ";
	(this->*_harlFunctions[i])();
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::_other(void)
{
	std::cout << "I need HOLIDAY!!!" << std::endl;
}