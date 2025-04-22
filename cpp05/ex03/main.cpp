/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:53:18 by yzhan             #+#    #+#             */
/*   Updated: 2025/04/14 10:53:19 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main()
{
	std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	Intern intern;

	std::cout << BLUE << "\n----------Normal Test----------\n\n" << WHITE;
	try	{
		AForm* shrub = intern.makeForm("shrubbery", "shrubForm");
		std::cout << *shrub << std::endl;
		delete shrub;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	
	// shrub->executeThis();
	// AForm* robot = intern.makeForm("robotomy", "robotForm");
	// robot->executeThis();
	// AForm* presi = intern.makeForm("presidential", "presiForm");
	// presi->executeThis();

	// std::cout << BLUE << "\n----------Invalid Test----------\n\n" << WHITE;
	// intern.makeForm("president", "presiForm");
	// intern.makeForm("", "presiForm");
	// AForm* wrong = intern.makeForm("president", "");
	// wrong->executeThis();
	// (void)wrong;
	// delete wrong;
	std::cout << BLUE  << "\n----------Testing Done----------\n\n" << WHITE;

	return 0;
}

//error on wsl
// main.cpp:33:17: error: deleting object of abstract class type ‘AForm’ which has non-virtual destructor will cause undefined behavior [-Werror=delete-non-virtual-dtor]                                                   33 |                 delete shrub;                                                                             |                 ^~~~~~~~~~~~                                                                        cc1plus: all warnings being treated as errors  