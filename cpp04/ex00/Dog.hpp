/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:12:17 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 16:12:19 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

#define GREEN "\033[32m"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog() override;
		Dog& operator=(const Dog& copy);

		void	makeSound() const override;
};
