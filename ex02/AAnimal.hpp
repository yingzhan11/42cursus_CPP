/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:03:31 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 15:03:33 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define WHITE "\033[0m"
#define BLUE "\033[34m"

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal();
		AAnimal& operator=(const AAnimal& copy);

		virtual void	makeSound() const = 0;
		std::string	getType() const;
		void	setType(const std::string newType);
};



