/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:58:52 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 09:58:54 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): _name("defaultDiamond")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "\033[36m" << "DiamondTrap default constructor called" << std::endl << "\033[0m";
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "\033[36m" << "DiamondTrap " << this->_name << " constructor called" << std::endl << "\033[0m";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
	std::cout << "\033[36m" << "DiamondTrap " << this->_name << " copy constructor called" << std::endl << "\033[0m";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[36m" << "DiamondTrap " << this->_name << " destructor called" << std::endl << "\033[0m";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy)
{
	if (this == & copy)
		return (*this);
	this->_name = copy._name;
	ClapTrap::operator=(copy);
	//ScavTrap::operator=(copy);
	//FragTrap::operator=(copy);
	std::cout << "\033[36m" << "DiamondTrap " << this->_name << " copy assignment operator called" << std::endl << "\033[0m";	
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap attack called" << std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Who Am I: \n";
	std::cout << "* My own name is: " << this->_name << std::endl;
	std::cout << "* My ClapTrap name is: " << ClapTrap::_name << std::endl;
	std::cout << "* My hitPoints is: " << this->_hitPoints << std::endl;
	std::cout << "* My energyPoints is: " << this->_energyPoints << std::endl;
	std::cout << "* My attackDamage is: " << this->_attackDamage << std::endl;
}

void DiamondTrap::printScavTrapValues() {
    std::cout << "ScavTrap Energy Points: " << ScavTrap::_energyPoints << std::endl;
}
