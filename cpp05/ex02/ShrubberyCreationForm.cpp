/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:53:06 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:53:08 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define	THE_TREE "\
        ccee88oo\n\
    C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP\n\
      \\//  /douUP\n\
        \\////\n\
         |||||\n\
         |||||\n\
         |||||\n"


ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery_Creation_Form", 145, 137, "unknow"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery_Creation_Form", 145, 137, target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm(copy){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

void ShrubberyCreationForm::executeForm() const
{
	std::ofstream output((this->getTarget() + "_shrubbery").c_str());

	if (!output)
		throw std::runtime_error("Error: Couldn't open the file in Shrubbery class");
	output << THE_TREE;
	output.close();
}