/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:03:40 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 15:03:41 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("defaultAAnimal")
{
	std::cout << BLUE << "AAnimal default constructor called" << std::endl << WHITE;
}

AAnimal::AAnimal(const AAnimal& copy): _type(copy._type)
{
	std::cout << BLUE << "AAnimal: " << this->_type << " copy constructor called" << std::endl << WHITE;
}

AAnimal::~AAnimal()
{
	std::cout << BLUE << "AAnimal: " << this->_type << " destructor called" << std::endl << WHITE;

}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	if (this == & copy)
		return (*this);
	this->_type = copy._type;
	std::cout << BLUE << "AAnimal: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

/**
 * Public functions
 */
std::string AAnimal::getType(void) const
{
	//std::cout << BLUE << "AAnimal get type: " << this->_type << " from it's field." << std::endl << WHITE;
	return (this->_type);
}

void	AAnimal::setType(const std::string newType)
{
	//std::cout << BLUE << "AAnimal set type: " << newType << " to it's type." << std::endl << WHITE;
	this->_type = newType;
}