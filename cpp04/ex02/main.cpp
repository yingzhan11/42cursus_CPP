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

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define AMOUNT 8
#define RED "\033[31m"

void	basicTest()
{
	//const AAnimal* Aanimal = nullptr;
    const AAnimal* dog = nullptr;
    const AAnimal* cat = nullptr;
    const WrongAnimal* wrongAnimal = nullptr;
    const WrongAnimal* wrongCat = nullptr;

	std::cout << "\n----------NormalTest----------\n\n";
	try
	{    
		//Aanimal = new AAnimal();
		dog = new Dog();
		cat = new Cat();
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete dog;
		delete cat;
		return ;
	}

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;

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
		return ;
	}
	
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	std::cout << std::endl;

	delete wrongCat;
	delete wrongAnimal;
}


int main()
{
	std::cout << "\n----------BasicTest----------\n\n";
	basicTest();

	std::cout << "\n----------AnimalArrayTest----------\n\n";
	std::cout << "\n---Constructor---\n\n";
	const AAnimal	*animal[AMOUNT];
	int i = 0;
	try {
		for (; i < AMOUNT; i++)
		{
			animal[i] = nullptr;
			if (i < AMOUNT / 2)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		for (int j = 0; j <= i; j++)
			delete animal[j];
		return 1;
	}

	std::cout << "\n---Make sound---\n\n";
	for (int j = 0; j < AMOUNT; j++)
		animal[j]->makeSound();
		
	std::cout << "\n---Destructor---\n\n";
	for (int j = 0; j < AMOUNT; j++)
		delete animal[j];
	
	return 0;
}