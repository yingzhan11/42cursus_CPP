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

	try
	{    
		std::cout << "\n----------NormalTest----------\n\n";
		animal = new Animal();
		std::cout << std::endl;

		dog = new Dog();
		std::cout << std::endl;

		cat = new Cat();
		std::cout << std::endl;

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << std::endl;

		cat->makeSound();
		dog->makeSound();
		animal->makeSound();
		std::cout << std::endl;

		delete dog;
		std::cout << std::endl;

		delete cat;
		std::cout << std::endl;

		delete animal;

		std::cout << "\n----------WrongCatTest----------\n\n";
		wrongAnimal = new WrongAnimal();
		std::cout << std::endl;
		
		wrongCat = new WrongCat();
		std::cout << std::endl;

		std::cout << wrongCat->getType() << " " << std::endl;
		std::cout << std::endl;

		wrongCat->makeSound();
		wrongAnimal->makeSound();
		std::cout << std::endl;

		delete wrongCat;
		std::cout << std::endl;

		delete wrongAnimal;
		
		std::cout << "\n----------Done----------\n\n";
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete dog;
		delete cat;
		delete animal;
		delete wrongCat;
		delete wrongAnimal;

		return 1;
	}
	return 0;
}