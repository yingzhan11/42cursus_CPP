/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:14 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 17:03:15 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define WHITE "\033[0m"
#define CYAN "\033[36m"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& copy);

		void	makeSound() const;
		std::string	getType() const;
		void	setType(const std::string newType);
};

