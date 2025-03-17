/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:42:07 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/17 14:42:10 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contactList[8];
		int		_totalContacts;
		int		_nextIndex;

		static void		_displayPhoneBook();
		static std::string	_displayFeild(const std::string &str);
		static int			_getIndex();

	public:
		PhoneBook();

		void	addContacts();
		void	searchContacts();
		
};

#endif
