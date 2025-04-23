/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:50:15 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:50:17 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& copy)
{
	if (this != &copy)
		_grade = copy._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increament()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreament()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	}catch (const std::exception& e){
		std::cerr << _name << " couldn't sign " << form.getName()
			<< ", because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "." << std::endl;
	}catch (const std::exception& e){
		std::cerr << _name << " couldn't execute " << form.getName()
			<< ", because " << e.what() << "." << std::endl; //need because or nor???
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "The Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "The Grade is too low.";
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return os;
}

