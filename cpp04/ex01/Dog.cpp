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
	std::cout << GREEN<< "Dog default constructor called" << std::endl << WHITE;
	this->_type = "Dog";
	try {
    	this->_brain = new Brain();
	} catch (const std::bad_alloc& e) {
    	std::cerr << "Memory allocation failed for _brain: " << this->_type << e.what() << std::endl;
	    exit(1);
	}
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << GREEN << "Dog: " << this->_type << " copy constructor called" << std::endl << WHITE;
	//this->_type = "Cat"; ?????
	try {
    	this->_brain = new Brain(*copy._brain);
	} catch (const std::bad_alloc& e) {
    	std::cerr << "Memory allocation failed for _brain: " << this->_type << e.what() << std::endl;
	    exit(1);
	}
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog: " << this->_type << " destructor called" << std::endl << WHITE;
	delete this->_brain;
	this->_brain = nullptr;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this == & copy)
		return (*this);
	Animal::operator=(copy);
	if (this->_brain != nullptr)
	{
		delete this->_brain;
		this->_brain = nullptr;
	}
	try {
    	this->_brain = new Brain(*copy._brain); // why here is pointer??
	} catch (const std::bad_alloc& e) {
    	std::cerr << "Memory allocation failed for _brain: " << this->_type << e.what() << std::endl;
	    exit(1);
	}
	std::cout << GREEN << "Dog: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << GREEN << "Dog makes sound: wwwwww!!!!!!" << std::endl << WHITE;
}