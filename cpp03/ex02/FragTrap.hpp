/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:19:14 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/25 14:19:15 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();
		FragTrap& operator=(const FragTrap& copy);
		
		void	attack(const std::string& target) override;
		void	highFivesGuys();
};



