/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:12:27 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 16:12:28 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>

# include "Animal.hpp"

# define PURPLE "\033[35m"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat() override;
		Cat& operator=(const Cat& copy);

		void	makeSound() const override;
};

#endif

