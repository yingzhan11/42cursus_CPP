/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:49:55 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:49:56 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("defaultForm"), _isSigned(false), _gradeToSign(150),
_gradeToExe(150), _target("default_target"){}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExe, const std::string& target)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe), _target(target)
{
	if (_gradeToSign < 1 || _gradeToExe < 1)
		throw GradeTooHighException("Grade is too high, failed to construct");
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw GradeTooLowException("Grade is too low, failed to construct");
}

AForm::AForm(const AForm& copy): _name(copy._name), _isSigned(copy._isSigned),
_gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe), _target(copy._target){}

AForm::~AForm(){}

AForm& AForm::operator = (const AForm& copy)
{
	if (this != &copy)
		_isSigned = copy._isSigned;
	return *this;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExe;
}

const std::string& AForm::getTarget() const
{
	return _target;
}

void AForm::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > _gradeToSign)
		throw GradeTooLowException("Grade is too low to sign");
	else
		_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException("Form isn't signed yet");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException("The executor's grade is too low, cann't execute");
	this->executeForm();
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message)
: _message(message){}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message)
: _message(message){}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return _message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& message)
: _message(message){}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return _message.c_str();
}

std::ostream& operator << (std::ostream& os, const AForm& form)
{
	os << "Form name: " << form.getName()
		<< "\nIs form signed: " << form.getIsSigned()
		<< "\nGrade to sign: " << form.getGradeToSign()
		<< "\nGrade to execute: " << form.getGradeToExecute()
		<< "\nTarget: " << form.getTarget()
		<< std::endl;
	return (os);
}
