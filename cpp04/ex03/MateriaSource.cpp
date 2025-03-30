/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:52:27 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/28 14:52:28 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}
//??????????
MateriaSource::~MateriaSource()
{
	void*	freeObjects[4] = {nullptr};
	int		freeCount = 0;

	for (int i = 0; i < 4; i++)
	{
		bool checkFree = false;
		for (int j = 0; j < freeCount; j++)
		{
			if (this->_inventory[i] == freeObjects[j])
			{
				checkFree = true;
				break ;
			}
		}
		if (!checkFree)
		{
			freeObjects[freeCount] = this->_inventory[i];
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
			freeCount++;
		}
	}
}

MateriaSource& MateriaSource::operator = (const MateriaSource& copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
		{
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
		if (copy._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
	}
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr && this->_inventory[i]->getType() == type)
		{
			return (this->_inventory[i]->clone());
		}
	}
	return (nullptr);
}

void MateriaSource::printMateria()
{
	std::cout << "printMateria:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
			std::cout << "inventory[" << i << "]: " << this->_inventory[i]->getType() << std::endl;
		else
			std::cout << "inventory[" << i << "]: empty" << std::endl;
		
	}
}