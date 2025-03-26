/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:19:05 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/25 14:19:06 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage =  30;
	std::cout << "\033[35m" << "FragTrap default constructor called" << std::endl << "\033[0m";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage =  30;
	std::cout << "\033[35m" << "FragTrap " << name << " constructor called" << std::endl << "\033[0m";
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << "\033[35m" << "FragTrap copy constructor called" << std::endl << "\033[0m";
}

FragTrap::~FragTrap()
{
	std::cout << "\033[35m" << "FragTrap " << this->_name << " destructor called" << std::endl << "\033[0m";
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	if (this == & copy)
		return (*this);
	ClapTrap::operator=(copy);
	std::cout << "\033[35m" << "FragTrap copy assignment operator called" << std::endl << "\033[0m";	
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a High Fives!." << std::endl;
}