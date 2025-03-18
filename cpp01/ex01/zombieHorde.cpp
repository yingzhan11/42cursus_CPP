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

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;

	Zombie* zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string uniqueName = name + std::to_string(i);
		zombie[i].setZombieName(uniqueName);
	}
	return (zombie);
}
