/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:51:07 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:51:08 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential_Pardon_Form", 25, 5, "unknow"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential_Pardon_Form", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

void PresidentialPardonForm::executeThis() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

