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

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>

# include "WrongAnimal.hpp"

# define PURPLE "\033[35m"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		~WrongCat() override;
		WrongCat& operator=(const WrongCat& copy);

		void	makeSound() const;
};

#endif

