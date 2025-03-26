/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:07:41 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/25 13:07:42 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\033[32m" << "ScavTrap default constructor called" << std::endl << "\033[0m";
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\033[32m" << "ScavTrap " << name << " constructor called" << std::endl << "\033[0m";
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	std::cout << "\033[32m" << "ScavTrap copy constructor called" << std::endl << "\033[0m";
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[32m" << "ScavTrap " << this->_name << " destructor called" << std::endl << "\033[0m";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	if (this == & copy)
		return (*this);
	ClapTrap::operator=(copy);
	std::cout << "\033[32m" << "ScavTrap copy assignment operator called" << std::endl << "\033[0m";	
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is dead. Can't attack others." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << "doesn't have any energy to attack." << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attck " << target
			<< ", causing " << this->_attackDamage << " points of damage!"<< std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}