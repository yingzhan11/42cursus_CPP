/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:30 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 17:03:32 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

#define CYAN "\033[36m"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		//WrongCat(const std::string& type);
		WrongCat(const WrongCat& copy);
		~WrongCat();
		WrongCat& operator=(const WrongCat& copy);

		void	makeSound() const override;
};
