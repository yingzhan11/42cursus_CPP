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
	std::cout << "\n---Constructor---\n\n";
	ClapTrap	Hero0;
	ClapTrap	Hero1("Hero1");
	// Copy constructor and copy assignment operator
	ClapTrap	copyHero(Hero1);
	Hero0 = Hero1;

	// Test attack
	std::cout << "\n----------Attack!----------\n\n";
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
	std::cout << "\n----------Kill!----------\n\n";
	Jerry.setAttackDamage(20);
	Jerry.attack("Tom");
	Tom.takeDamage(Jerry.getAttackDamage());
	Tom.beRepaired(10);
	Jerry.attack("Tom");
	Tom.takeDamage(Jerry.getAttackDamage());
	
	std::cout << "\n----------Done----------\n\n";

	return 0;
}
