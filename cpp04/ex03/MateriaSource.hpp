/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:52:32 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/28 14:52:33 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _inventory[4];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource() override;

		MateriaSource& operator = (const MateriaSource& copy);

		void learnMateria(AMateria* m) override;
		AMateria* createMateria(std::string const & type) override;
		
		void printMateria() override;
};

#endif
