/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:12:33 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 16:12:34 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << GREEN<< "Dog default constructor called" << std::endl << WHITE;
}

//Dog::Dog(const std::string& type): Animal(type)
//{
//	this->_type = "Dog";
//	std::cout << GREEN << "Dog " << this->_type << " constructor called" << std::endl << WHITE;

//}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << GREEN << "Dog: " << this->_type << " copy constructor called" << std::endl << WHITE;
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog: " << this->_type << " destructor called" << std::endl << WHITE;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this == & copy)
		return (*this);
	this->_type = copy._type;
	std::cout << GREEN << "Dog: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << GREEN << "Dog makes sound: wwwwww!!!!!!" << std::endl << WHITE;
}