/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:53:03 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/27 10:53:05 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GOLD << "Brain default constructor called" << std::endl << WHITE;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "default idea";
}

Brain::Brain(const Brain& copy)
{
	std::cout << GOLD << "Brain copy constructor called" << std::endl << WHITE;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain::~Brain()
{
	std::cout << GOLD << "Brain destructor called" << std::endl << WHITE;
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout << GOLD << "Brain copy assignment operator called" << std::endl << WHITE;
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (_ideas[i]);
	else
		return ("");
}

void	Brain::setIdea(int i, const std::string& newidea)
{
	if (i >= 0 && i < 100)
		_ideas[i] = newidea;
}
