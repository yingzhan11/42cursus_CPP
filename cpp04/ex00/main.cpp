/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:03:19 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/26 15:03:22 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <limits>

#define RED "\033[31m"

int main()
{
	const Animal* animal = nullptr;
    const Animal* dog = nullptr;
    const Animal* cat = nullptr;
    const WrongAnimal* wrongAnimal = nullptr;
    const WrongAnimal* wrongCat = nullptr;

	std::cout << "\n----------NormalTest----------\n\n";
	try
	{    
		animal = new Animal();
		dog = new Dog();
		cat = new Cat();
		//throw std::bad_alloc();
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete dog;
		delete cat;
		delete animal;
		return 1;
	}

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete animal;

	std::cout << "\n----------WrongCatTest----------\n\n";
	try
	{    
		wrongAnimal = new WrongAnimal();
		wrongCat = new WrongCat();
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete wrongCat;
		delete wrongAnimal;
		return 1;
	}
	
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	std::cout << std::endl;

	delete wrongCat;
	delete wrongAnimal;
		
	std::cout << "\n----------Done----------\n\n";
	return 0;
}