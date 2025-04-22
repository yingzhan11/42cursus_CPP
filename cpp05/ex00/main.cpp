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

int main()
{
	std::cout << "\n----------Test----------\n\n";
	std::cout << "\n---Normal test of constructor---\n\n";
	try{
		Bureaucrat testA;
		std::cout << testA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat testB("testB", 1);
		std::cout << testB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat testC("testB", 100);
		std::cout << testC << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---TooHigh grade---\n\n";
	try{
		Bureaucrat testHighA("testHigh", 0);
		std::cout << testHighA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat testHighB("testHigh", -3);
		std::cout << testHighB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---TooLow grade---\n\n";
	try{
		Bureaucrat testLowA("testLow", 151);
		std::cout << testLowA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat testLowB("testLow", 200);
		std::cout << testLowB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---Increment---\n\n";
	try{
		Bureaucrat testIn("testIn", 3);
		std::cout << testIn << std::endl;

		testIn.increament();
		std::cout << testIn << std::endl;

		testIn.increament();
		std::cout << testIn << std::endl;


		testIn.increament();
		std::cout << testIn << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---Decrement---\n\n";
	try{
		Bureaucrat testDe("testDe", 148);
		std::cout << testDe << std::endl;

		testDe.decreament();
		std::cout << testDe << std::endl;

		testDe.decreament();
		std::cout << testDe << std::endl;

		testDe.decreament();
		std::cout << testDe << std::endl;

	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n----------Done----------\n\n";

	return 0;
}
