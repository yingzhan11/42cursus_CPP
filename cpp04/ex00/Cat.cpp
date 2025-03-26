/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:12:39 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 16:12:41 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << PURPLE << "Cat default constructor called" << std::endl << WHITE;
}

//Cat::Cat(const std::string& type): Animal(type)
//{
//	this->_type = "Cat";
//	std::cout << "\033[34m" << "Cat " << this->_type << " constructor called" << std::endl << WHITE;

//}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << PURPLE << "Cat: " << this->_type << " copy constructor called" << std::endl << WHITE;
}

Cat::~Cat()
{
	std::cout << PURPLE << "Cat: " << this->_type << " destructor called" << std::endl << WHITE;
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this == & copy)
		return (*this);
	this->_type = copy._type;
	std::cout << PURPLE << "Cat: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "Cat makes sound: mmmmmm~~~~~~" << std::endl << WHITE;
}
