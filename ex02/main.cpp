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

int main()
{
	//const AAnimal* AAnimal = nullptr;
    const AAnimal* dog = nullptr;
    const AAnimal* cat = nullptr;
    const WrongAnimal* wrongAnimal = nullptr;
    const WrongAnimal* wrongCat = nullptr;

	try
	{
		std::cout << "\n----------NormalTest----------\n\n";
		//AAnimal = new AAnimal();
		dog = new Dog();
		cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		//AAnimal->makeSound();

		delete dog;
		delete cat;
		//delete AAnimal;

		std::cout << "\n----------WrongCatTest----------\n\n";
		wrongAnimal = new WrongAnimal();
		wrongCat = new WrongCat();

		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		wrongAnimal->makeSound();

		delete wrongCat;
		delete wrongAnimal;
		
		std::cout << "\n----------Done----------\n\n";
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		
		delete dog;
		delete cat;
		//delete AAnimal;
		delete wrongCat;
		delete wrongAnimal;

		return 1;
	}

	std::cout << "\n----------AnimalArrayTest----------\n\n";
	std::cout << "\n---Constructor---\n\n";
	const AAnimal	*animal[AMOUNT];
	int i = 0;
	try {
		for (; i < AMOUNT; i++)
		{
			if (i < AMOUNT / 2)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}
		std::cout << "\n---Make sound---\n\n";
		for (int i = 0; i < AMOUNT; i++)
			animal[i]->makeSound();
		
		std::cout << "\n---Destructor---\n\n";
		for (int i = 0; i < AMOUNT; i++)
			delete animal[i];
		std::cout << "\n----------Done----------\n\n";
	} catch (const std::bad_alloc& e) {
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		//std::cout << i << std::endl;
		for (int j = 0; j < i -1; j--)
			delete animal[j];
		return 1;
	}
	
	return 0;
}