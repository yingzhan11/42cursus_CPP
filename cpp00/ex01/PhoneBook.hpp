#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contactList[8];
		int		_totalContacts;
		int		_nextIndex;

		bool	_isOnlySpace(const std::string &str);

	public:
		PhoneBook();
		//functions
		void	addContact();
		void	searchContact(PhoneBook &phoneBook);
};

#endif