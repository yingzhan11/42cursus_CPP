#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		//constructor
		Contact();
		
		//functions
		void	fieldPrompt();
		void	addField();
};

#endif