/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:27:53 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/31 15:27:54 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//std::cout << "\n----------Materia test----------\n\n";
	std::cout << "\n---Default constructor---\n\n";
	Form testA;
	std::cout << testA << std::endl;

	std::cout << "\n---Parameter constructor---\n\n";
	Form testB("testB", 1, 150);
	std::cout << testB << std::endl;
	
	Form testC("testC", 150, 1);
	std::cout << testC << std::endl;
	

	std::cout << "\n---TooHigh parameter constructor---\n\n";
	try{
		Form testHighA("testHighA", 0, 42);
		std::cout << testHighA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form testHighB("testHighB", 42, -3);
		std::cout << testHighB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---TooLow parameter constructor---\n\n";
	try{
		Form testLowA("testLowA", 151, 42);
		std::cout << testLowA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	try{
		Form testLowB("testLowB", 42, 200);
		std::cout << testLowB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---Sign Test---\n\n";
	Form formTest("FormTest", 24, 42);
	std::cout << formTest << std::endl;
	Bureaucrat	formA("A", 20);
	Bureaucrat	formB("B", 24);
	Bureaucrat	formC("C", 25);
	Bureaucrat	formD("D", 42);
	Bureaucrat	formE("E", 50);

	formA.signForm(formTest);
	formB.signForm(formTest);
	formC.signForm(formTest);
	formD.signForm(formTest);
	formE.signForm(formTest);

	formC.increament();
	formC.signForm(formTest);
	formB.decreament();
	formB.signForm(formTest);
	

	std::cout << "\n----------Done----------\n\n";

	return 0;
}
