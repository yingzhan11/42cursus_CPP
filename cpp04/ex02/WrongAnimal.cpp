/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:21 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 17:03:22 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("defaultWrongAnimal")
{
	std::cout << CYAN << "WrongAnimal default constructor called" << std::endl << WHITE;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy): _type(copy._type)
{
	std::cout << CYAN << "WrongAnimal: " << this->_type << " copy constructor called" << std::endl << WHITE;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << CYAN << "WrongAnimal: " << this->_type << " destructor called" << std::endl << WHITE;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this == & copy)
		return (*this);
	this->_type = copy._type;
	std::cout << CYAN << "WrongAnimal: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

/**
 * Public functions
 */
void	WrongAnimal::makeSound() const
{
	std::cout << CYAN << "WrongAnimal makes sound: ??????" << std::endl << WHITE;
}

std::string WrongAnimal::getType(void) const
{
	std::cout << CYAN << "WrongAnimal get type: " << this->_type << " from it's field." << std::endl << WHITE;
	return (this->_type);
}

void	WrongAnimal::setType(const std::string newType)
{
	std::cout << CYAN << "WrongAnimal set type: " << newType << " to it's type." << std::endl << WHITE;
	this->_type = newType;
}
