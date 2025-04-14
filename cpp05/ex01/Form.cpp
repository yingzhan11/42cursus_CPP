/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:47:25 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/31 16:47:26 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("defaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExe(150){}

Form::Form(const std::string name, int gradeToSign, int gradeToExe): _name(name),
_isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	if (_gradeToSign < 1 || _gradeToExe < 1)
		throw GradeTooHighException("Grade is too high, failed to construct");
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw GradeTooLowException("Grade is too low, failed to construct");
}

Form::Form(const Form& copy): _name(copy._name), _isSigned(copy._isSigned),
_gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe){}

Form::~Form(){}

Form& Form::operator = (const Form& copy)
{
	if (this != &copy)
		_isSigned = copy._isSigned;
	return *this;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExe;
}

void Form::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > _gradeToSign)
		throw GradeTooLowException("Grade is too low to sign");
	else
		_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& message)
: _message(message){}

const char* Form::GradeTooHighException::what() const noexcept
{
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message)
: _message(message){}

const char* Form::GradeTooLowException::what() const noexcept
{
	return _message.c_str();
}

std::ostream& operator << (std::ostream& os, const Form& form)
{
	os << "Form name: " << form.getName()
		<< "\nIs form signed: " << form.getIsSigned()
		<< "\nGrade to sign: " << form.getGradeToSign()
		<< "\nGrade to execute: " << form.getGradeToExecute()
		<< std::endl;
	return (os);
}