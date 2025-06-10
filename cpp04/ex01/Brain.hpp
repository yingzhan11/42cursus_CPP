/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:53:12 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/27 10:53:14 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define WHITE "\033[0m"
#define GOLD "\033[33m"

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();
		Brain& operator=(const Brain& copy);

		std::string getIdea(int i) const;
		void	setIdea(int i, const std::string& newidea);
};



