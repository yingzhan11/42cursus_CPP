/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:37:16 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 13:37:17 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//PTR and REF
int	main(void)
{
	int	amount = 10;
	
	Zombie* zombie = zombieHorde(amount, "Azooo_");

	for (int i = 0; i < amount; i++)
	{
		zombie[i].announce();
	}
	delete [] zombie;
	return 0;
}