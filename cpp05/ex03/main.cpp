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
		std::cout << std::endl << *shrub << std::endl;
		delete shrub;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	try	{
		AForm* robot = intern.makeForm("robotomy", "robotForm");
		std::cout << std::endl << *robot << std::endl;
		delete robot;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* presi = intern.makeForm("presidential", "presiForm");
		std::cout << std::endl << *presi << std::endl;
		delete presi;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE << "\n----------Invalid Test----------\n\n" << WHITE;

	try	{
		AForm* invalidType = intern.makeForm("nothing", "presiForm");
		std::cout << std::endl << *invalidType << std::endl;
		delete invalidType;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* noType = intern.makeForm("", "presiForm");
		std::cout << std::endl << *noType << std::endl;
		delete noType;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* noTarget = intern.makeForm("presidential", "");
		std::cout << std::endl << *noTarget<< std::endl;
		delete noTarget;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  << "\n----------Testing Done----------\n\n" << WHITE;

	return 0;
}
