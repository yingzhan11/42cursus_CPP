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

#include "DiamondTrap.hpp"

void	constructorTest()
{
	// Default constructor and constructor with name
	std::cout << "\n---Default constructor---\n\n";
	DiamondTrap	DiamondHero0;
	DiamondHero0.whoAmI();
	std::cout << "\n---Parameter constructor---\n\n";
	DiamondTrap	DiamondHero1("Hero1");
	DiamondHero1.whoAmI();

	// Copy constructor and copy assignment operator
	//std::cout << "\n---Copy constructor & Copy assignment operator---\n\n";
	//DiamondHero1.setAttackDamage(100);
	//DiamondHero1.whoAmI();

	std::cout << "\n---Copy constructor---\n\n";
	DiamondTrap	copyHero(DiamondHero1);
	copyHero.whoAmI();

	std::cout << "\n---Copy assignment operator---\n\n";
	DiamondHero0 = DiamondHero1;
	DiamondHero0.whoAmI();

	std::cout << "\n---Destructor---\n\n";
}

int	main(void)
{

	std::cout << "\n----------DiamondTrapTest----------\n\n";
	constructorTest();
	
	// Test attack
	std::cout << "\n----------DiamondTrap Attack Test----------\n\n";
	std::cout << "\n---Attack!---\n\n";
	DiamondTrap	Tom("Tom");
	DiamondTrap	Jerry("Jerry");
	Tom.attack("Jerry");
	Jerry.takeDamage(Tom.getAttackDamage());
	Jerry.beRepaired(10);

	// kill one
	std::cout << "\n---Kill!---\n\n";
	Jerry.setAttackDamage(200);
	Jerry.attack("Tom");
	Tom.takeDamage(Jerry.getAttackDamage());
	Tom.beRepaired(10);
	Jerry.attack("Tom");
	Tom.takeDamage(10);
	
	std::cout << "\n----------Done----------\n\n";

	return 0;
}
