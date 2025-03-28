/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:50:45 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/28 14:50:46 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("Empty"){}

AMateria::AMateria(std::string const& type): _type(type){}

AMateria::AMateria(const AMateria& copy): AMateria(copy._type){}

AMateria::~AMateria(){}

AMateria& AMateria::operator = (const AMateria& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}


const std::string&	AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "The character " << target.getName() << " use " << this->_type << " of AMateria." << std::endl; // what info put here????
}