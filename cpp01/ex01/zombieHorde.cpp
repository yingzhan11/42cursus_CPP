/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:37:46 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 13:37:48 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// give all zombie the same name now, i want name with nbr
Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].setZombieName(name);
	return (zombie);
}
