/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:50:23 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:50:24 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		Bureaucrat& operator = (const Bureaucrat& copy);

		const std::string& getName() const;
		int getGrade() const;

		void increament();
		void decreament();

		void signForm(AForm& form);
		void executeForm(const AForm& form);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureau);

#endif
