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

	std::cout << BLUE  << "\n----------Start Testing----------\n\n" << WHITE;
	std::cout << BLUE  << "\n---Create Executors---\n\n" << WHITE;
	Bureaucrat	boss("Boss", 5);
	Bureaucrat	manager("Manager", 45);
	Bureaucrat	worker("Workder", 137);
	Bureaucrat	intern("intern", 149);

	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << worker << std::endl;
	std::cout << intern << std::endl;

	std::cout << BLUE  << "\n----------Shrubbery Testing----------\n\n" << WHITE;
	std::cout << BLUE  << "\n---Create ShrubberyCreationForm---\n\n" << WHITE;
	ShrubberyCreationForm shrubForm("shrubForm");
	std::cout << shrubForm << std::endl;

	std::cout << BLUE  << "\n---Lower Grade Executor---\n" << WHITE;
	std::cout << BLUE  << "\n-Execute Unsigned Form-\n\n" << WHITE;
	try	{
		shrubForm.execute(intern);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  << "\n-Sign the Form-\n\n" << WHITE;
	try	{
		shrubForm.beSigned(intern);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  << "\n---Higher Grade Executor---\n" << WHITE;
	std::cout << BLUE  << "\n-Execute Unsigned Form-\n\n" << WHITE;
	try	{
		shrubForm.execute(boss);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  << "\n-Sign the Form-\n\n" << WHITE;
	try	{
		shrubForm.beSigned(boss);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << shrubForm << std::endl;

	std::cout << BLUE  << "\n---Execute Signed Form---\n" << WHITE;
	std::cout << BLUE  << "\n-Higher Grade Executor-\n\n" << WHITE;
	try	{
		shrubForm.execute(boss);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  << "\n-Lower Grade Executor-\n\n" << WHITE;
	try	{
		shrubForm.execute(intern);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  << "\n----------Shrubbery Testing Done----------\n\n" << WHITE;

	//std::cout << "\n----------Robotomy Testing----------\n\n";
	//std::cout << "\n---Create RobotomyRequestForm---\n\n";
	//RobotomyRequestForm robotForm("shrubForm");
	//std::cout << robotForm << std::endl;

	//std::cout << "\n---Execute Unsigned Form with higher grade executor---\n\n";
	//try	{
	//	robotForm.execute(boss);
	//} catch(const std::exception& e) {
	//	std::cerr << e.what() << '\n';
	//}

	//std::cout << "\n---Execute Unsigned Form with lower grade executor---\n\n";
	//try	{
	//	robotForm.execute(nobody);
	//} catch(const std::exception& e) {
	//	std::cerr << e.what() << '\n';
	//}

	//std::cout << "\n---Sign the Form---\n\n";
	//robotForm.beSigned(boss);
	//std::cout << robotForm << std::endl;

	//std::cout << "\n---Execute Signed Form with higher grade executor---\n\n";
	//try	{
	//	robotForm.execute(boss);
	//} catch(const std::exception& e) {
	//	std::cerr << e.what() << '\n';
	//}

	//std::cout << "\n---Execute Signed Form with lower grade executor---\n\n";
	//try	{
	//	robotForm.execute(nobody);
	//} catch(const std::exception& e) {
	//	std::cerr << e.what() << '\n';
	//}
	
	//std::cout << "\n----------Shrubbery Testing Done----------\n\n";

	
	

	return 0;
}
