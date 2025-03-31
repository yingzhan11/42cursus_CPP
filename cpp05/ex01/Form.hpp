/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:47:20 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/31 16:47:22 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExe);
		Form(const Form& copy);
		~Form();

		Form& operator = (const Form& copy);

		const std::string& getName() const;
		bool getIsSigned() const;

		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const )

		void increament();
		void decreament();

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

std::ostream& operator << (std::ostream& os, const Form& bure);

