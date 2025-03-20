/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:40:36 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 13:40:38 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _weapon(nullptr){}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " has no weapon to use" << std::endl;
		return ;
	}
	std::cout << this->_name << " attack with " << this->_weapon->getType() << std::endl;
}