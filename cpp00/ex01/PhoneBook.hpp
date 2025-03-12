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

		void		_displayPhoneBook();
		std::string	_displayFeild(const std::string &str);
		int			_getIndex();

	public:
		PhoneBook();
		//functions
		void	addContact();
		void	searchContact();
		
};

#endif