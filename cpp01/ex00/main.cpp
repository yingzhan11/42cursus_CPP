/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:35:55 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 13:35:57 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//stack and heap
int	main(void)
{
	// test announce
	Zombie zombieA("Azooo");
	zombieA.announce();

	// test stack and destructor
	randomChump("Bzooo");

	// test heap
	Zombie	*zombieC = newZombie("Czooo");
	Zombie	*zombieD = newZombie("Dzooo");
	zombieC->announce();
	zombieD->announce();

	delete(zombieC);
	delete(zombieD);
	return 0;
}
