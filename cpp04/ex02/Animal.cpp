/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:03:40 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 15:03:41 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("defaultAnimal")
{
	std::cout << BLUE << "Animal default constructor called" << std::endl << WHITE;
}

Animal::Animal(const Animal& copy): _type(copy._type)
{
	std::cout << BLUE << "Animal: " << this->_type << " copy constructor called" << std::endl << WHITE;
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal: " << this->_type << " destructor called" << std::endl << WHITE;

}

Animal& Animal::operator=(const Animal& copy)
{
	if (this == & copy)
		return (*this);
	this->_type = copy._type;
	std::cout << BLUE << "Animal: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

/**
 * Public functions
 */
void	Animal::makeSound() const
{
	std::cout << BLUE << "Animal makes sound: ......" << std::endl << WHITE;
}

std::string Animal::getType(void) const
{
	//std::cout << BLUE << "Animal get type: " << this->_type << " from it's field." << std::endl << WHITE;
	return (this->_type);
}

void	Animal::setType(const std::string newType)
{
	//std::cout << BLUE << "Animal set type: " << newType << " to it's type." << std::endl << WHITE;
	this->_type = newType;
}