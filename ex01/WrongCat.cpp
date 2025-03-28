/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:40 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 17:03:41 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << PURPLE << "WrongCat default constructor called" << std::endl << WHITE;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << PURPLE << "WrongCat: " << this->_type << " copy constructor called" << std::endl << WHITE;
}

WrongCat::~WrongCat()
{
	std::cout << PURPLE << "WrongCat: " << this->_type << " destructor called" << std::endl << WHITE;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this == & copy)
		return (*this);
	this->_type = copy._type;
	std::cout << PURPLE << "WrongCat: " << this->_type << " copy assignment operator called" << std::endl << WHITE;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << PURPLE << "WrongCat makes sound: MMMMMM??????" << std::endl << WHITE;
}

