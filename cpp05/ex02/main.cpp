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
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main()
{
	std::cout << BLUE << "\n----------Constructor Test----------\n\n" << WHITE;
	ShrubberyCreationForm shrub;
	RobotomyRequestForm robot;
	PresidentialPardonForm presi;

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << presi << std::endl;

	std::cout << BLUE << "\n----------Start Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Create Executors---\n\n" << WHITE;
	Bureaucrat	manager("manager", 5); // need try catch here
	Bureaucrat	intern("intern", 150);
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	std::cout << BLUE << "\n----------Shrubbery Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Create ShrubberyCreationForm---\n\n" << WHITE;
	ShrubberyCreationForm shrubForm("shrubForm");
	std::cout << shrubForm << std::endl;

	std::cout << BLUE << "\n---Execute Unsigned Form---\n" << WHITE;
	try	{
		intern.executeForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.executeForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE << "\n---Sign the Form---\n" << WHITE;
	try	{
		intern.signForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.signForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << shrubForm << std::endl;

	std::cout << BLUE << "\n---Execute Signed Form---\n" << WHITE;
	try	{
		intern.executeForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.executeForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE << "\n----------Shrubbery Testing Done----------\n\n" << WHITE;

	std::cout << BLUE << "\n----------Robotomy Testing----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Create RobotomyRequestForm---\n\n" << WHITE;
	RobotomyRequestForm robotForm("robotForm");
	std::cout << robotForm << std::endl;

	std::cout << BLUE << "\n---Execute Unsigned Form---\n" << WHITE;
	try	{
		intern.executeForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.executeForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE << "\n---Sign the Form---\n" << WHITE;
	try	{
		intern.signForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.signForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << robotForm << std::endl;

	std::cout << BLUE << "\n---Execute Signed Form---\n" << WHITE;
	try	{
		intern.executeForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.executeForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE << "\n----------Robotomy Testing Done----------\n\n" << WHITE;
	
	std::cout << BLUE << "\n----------President Testing----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Create PresidentialPardonForm---\n\n" << WHITE;
	PresidentialPardonForm presiForm("presiForm");
	std::cout << presiForm << std::endl;

	std::cout << BLUE << "\n---Execute Unsigned Form---\n" << WHITE;
	try	{
		intern.executeForm(presiForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.executeForm(presiForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE << "\n---Sign the Form---\n" << WHITE;
	try	{
		intern.executeForm(presiForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.signForm(presiForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << presiForm << std::endl;

	std::cout << BLUE  << "\n---Execute Signed Form---\n" << WHITE;
	try	{
		intern.executeForm(presiForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{
		manager.executeForm(presiForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  << "\n----------President Testing Done----------\n\n" << WHITE;

	return 0;
}
