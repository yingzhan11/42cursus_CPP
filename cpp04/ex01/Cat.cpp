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
	std::cout << PURPLE << "Cat default constructor called" << std::endl << WHITE;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << PURPLE << "Cat: " << this->_type << " copy constructor called" << std::endl << WHITE;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
	std::cout << PURPLE << "Cat: " << this->_type << " destructor called" << std::endl << WHITE;
	delete this->_brain;
	this->_brain = nullptr;
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this == & copy)
		return (*this);
	Animal::operator=(copy);
	if (this->_brain != nullptr)
	{
		delete this->_brain;
		this->_brain = nullptr;
	}
	this->_brain = new Brain(*copy._brain);
	std::cout << PURPLE << "Cat: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "Cat makes sound: mmmmmm~~~~~~" << std::endl << WHITE;
}

Brain*	Cat::getBrain() const
{
	if (this->_brain != nullptr)
		return (this->_brain);
	else
		return (nullptr);
}