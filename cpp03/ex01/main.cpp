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

#include "ScavTrap.hpp"

int	main(void)
{

	std::cout << "\n----------ScavTrapTest----------\n\n";
	// Default constructor and constructor with name
	std::cout << "\n---Constructor---\n\n";
	ScavTrap	ScavHero0;
	ScavTrap	ScavHero1("ScavHero1");
	// Copy constructor and copy assignment operator
	ScavTrap	copyScavHero(ScavHero1);
	ScavHero0 = ScavHero1;
	// Test guardGate
	ScavHero0.guardGate();
	ScavHero1.guardGate();
	copyScavHero.guardGate();

	// Test attack
	std::cout << "\n----------Attack!----------\n\n";
	ScavTrap	Tom("Tom");
	ScavTrap	Jerry("Jerry");
	Tom.attack("Jerry");
	Jerry.takeDamage(Tom.getAttackDamage());
	Jerry.beRepaired(10);

	//// kill one
	std::cout << "\n----------Kill!----------\n\n";
	Jerry.setAttackDamage(200);
	Jerry.attack("Tom");
	Tom.takeDamage(Jerry.getAttackDamage());
	Tom.beRepaired(10);
	Jerry.attack("Tom");
	Tom.takeDamage(10);

	std::cout << "\n----------Done----------\n\n";

	return 0;
}
