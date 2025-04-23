/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:51:41 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:51:43 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy_Request_Form", 72, 45, "unknow"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy_Request_Form", 72, 45, target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm(copy){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

void RobotomyRequestForm::executeThis() const
{
	std::cout << "Drilling noises: ZZZZ ZZZZZ ZZZZZZZ" << std::endl;
	
	// get current time of program running, to set a seed for random number
	std::srand(std::time(0));
	bool isSuccess = std::rand() % 2;
	if (isSuccess)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed" << std::endl;
}
