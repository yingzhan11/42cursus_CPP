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
		//enum
		enum field{FIRSTNAME, LASTNAME, NICKNAME, PHONENUMBER, DARKESTSECRET};

		//constructor
		Contact();
		
		//functions
		void		fieldPrompt(int i);
		bool		isEmptyInput(const std::string &str);
		bool		isValidPhoneNumber(const std::string &phoneNumber);
		void		addField(int i, const std::string &str);
		std::string	getName(int i);
		void		printContact();
};

#endif