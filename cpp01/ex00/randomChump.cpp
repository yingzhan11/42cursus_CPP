/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:36:10 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 13:36:12 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Create Zombie in stack, and annouce it, for using local
void	randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}
