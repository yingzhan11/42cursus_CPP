/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:50:55 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/28 14:50:56 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("empty")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}
Character::Character(const std::string& name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}
Character::Character(const Character& copy): _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
	}
}

Character& Character::operator = (const Character& copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		// delete materia before add new one
		if (this->_inventory[i] != nullptr)
		{
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
		// add new materia
		if (copy._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return _name;
}
void Character::equip(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	else if (this->_inventory[idx] == nullptr)
		return ;
	else
		this->_inventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	else if (this->_inventory[idx] != nullptr)
		this->_inventory[idx]->use(target);
}

AMateria	*Character::getInventory(int idx){
	if (idx < 0 || idx > 3)
		return (nullptr);
	return (this->_inventory[idx]);
}