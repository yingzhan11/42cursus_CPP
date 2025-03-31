/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:28:21 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/31 15:28:27 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
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

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "The Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "The Grade is too low.";
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& bure)
{
	os << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".";
	return os;
}

