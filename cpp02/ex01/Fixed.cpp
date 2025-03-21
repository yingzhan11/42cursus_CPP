/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:28:46 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/21 15:28:48 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * Constructor
 */
// Constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Int copy constructor, to convert int to fixed point number, shifting the value left by fract_bits
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fractionalBits;
}

// Float copy constructor, to convert float to fixed point number, value * 2^_fractionalBits
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Copy assignment
Fixed& Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = copy.getRawBits();
	}
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * Public functions
 */
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// Convert fixed point number back to integer, shifting right
int	Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

// Convert fixed point number back to float, and make sure it is float.
float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fractionalBits));
}

/**
 * Other function
 */
// define operator << to print fixed number by convert it to float
std::ostream&	operator << (std::ostream& os, const Fixed& number)
{
	os << number.toFloat();
	return (os);
}
