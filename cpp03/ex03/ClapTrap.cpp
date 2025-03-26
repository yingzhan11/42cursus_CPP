/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:32:15 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/25 10:32:17 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10),
_attackDamage(0)
{
	std::cout << "\033[34m" << "ClapTrap default constructor called" << std::endl << "\033[0m";
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10),
_attackDamage(0)
{
	std::cout << "\033[34m" << "ClapTrap " << this->_name << " constructor called" << std::endl << "\033[0m";
}

ClapTrap::ClapTrap(const ClapTrap& copy): _name(copy._name), _hitPoints(copy._hitPoints),
_energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "\033[34m" << "ClapTrap " << this->_name << " copy constructor called" << std::endl << "\033[0m";
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[34m" << "ClapTrap " << this->_name << " destructor called" << std::endl << "\033[0m";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	if (this == & copy)
		return (*this);
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "\033[34m" << "ClapTrap " << this->_name << " copy assignment operator called" << std::endl << "\033[0m";
	return (*this);
}

/**
 * Public functions
 */
void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead. Can't attack others." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << "doesn't have any energy to attack." << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attcks " << target
			<< ", causing " << this->_attackDamage << " points of damage!"<< std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead. Can't take any more damage." << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage! Now it's hitPoints is "
		<< this->_hitPoints << "." << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "\033[31m" << "ClapTrap " << this->_name << " is dead!" << std::endl << "\033[0m";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead. Can't be repaired." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << "doesn't have any energy to repaire." << std::endl;
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " be reparied, and get "
			<< amount << " hitPoints. Now it's hitPoints is " << this->_hitPoints << "."<< std::endl;
	}
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	std::cout << "\033[33m" << "ClapTrap get " << this->_name << "'s damage amout." << std::endl << "\033[0m";
	return (this->_attackDamage);
}

void	ClapTrap::setAttackDamage(const int damage)
{
	std::cout << "\033[33m" << "ClapTrap set " << damage << " to " << this->_name << "'s attackDamage." << std::endl << "\033[0m";
	this->_attackDamage = damage;
}
