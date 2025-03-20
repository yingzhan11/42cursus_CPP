/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:31:41 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 14:31:42 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	private:
		std::string	_level[5];
		void	(Harl::*_harlFunctions[5])(void);
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
		void	_other(void);

	public:
		Harl(void);
		~Harl(void);

		void	complain( std::string level );
};



#endif
