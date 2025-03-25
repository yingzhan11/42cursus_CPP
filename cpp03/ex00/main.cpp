/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:31:56 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/25 10:31:57 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	// Default constructor and constructor with name
	ClapTrap	Hero0;
	ClapTrap	Hero1("Hero1");
	// Copy constructor and copy assignment operator
	ClapTrap	copyHero0(Hero0);
	ClapTrap	copyHero1(Hero1);
	Hero0 = Hero1;

	// Test attack
	std::cout << "[ Attack! ]\n";
	ClapTrap	Tom("Tom");
	ClapTrap	Jerry("Jerry");
	Tom.attack("Jerry");
	Jerry.takeDamage(Tom.getAttackDamage());
	// Set damage for Tom
	Tom.setAttackDamage(9);
	Tom.attack("Jerry");
	Jerry.takeDamage(Tom.getAttackDamage());
	Jerry.beRepaired(10);

	// kill one
	std::cout << "[ Kill! ]\n";
	Jerry.setAttackDamage(20);
	Jerry.attack("Tom");
	Tom.takeDamage(Jerry.getAttackDamage());
	Tom.beRepaired(10);
	Jerry.attack("Tom");
	Tom.takeDamage(10);
	std::cout << "[ Done ]\n";

	return 0;
}
