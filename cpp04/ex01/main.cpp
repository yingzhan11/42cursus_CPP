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

#define AMOUNT 8

void	basicTest()
{
	std::cout << "\n----------NormalTest----------\n\n";
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();

	delete dog;
	dog = nullptr;
	delete cat;
	cat = nullptr;
	delete animal;
	animal = nullptr;

	std::cout << "\n----------WrongCatTest----------\n\n";
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrong->makeSound();
	
	delete wrongCat;
	wrongCat = nullptr;
	delete wrong;
	wrong = nullptr;
}

int main()
{

	// add memory check here
	std::cout << "\n----------BasicTest----------\n\n";
	basicTest();
	
	std::cout << "\n----------AnimalArrayTest----------\n\n";
	const Animal	*animal[AMOUNT];

	std::cout << "\n---Constructor---\n\n";
	for (int i = 0; i < AMOUNT; i++)
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
	{
		delete animal[i];
		animal[i] = nullptr;
	}

	std::cout << "\n----------DeepCopyTest----------\n\n";
	std::cout << "\n---Copy---\n\n";
	Cat	cat;
	Cat	copyCat(cat);
	Cat	operatorCopyCat = cat;
	std::cout << "\n---Default idea---\n\n";
	std::cout << "cat brain idea[0]: " << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << "copyCat brain idea[0]: " << copyCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "operatorCopyCat brain idea[0]: " << operatorCopyCat.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\n---Set a new idea---\n\n";
	copyCat.getBrain()->setIdea(0, "I want fishfishfish!");
	operatorCopyCat.getBrain()->setIdea(0, "Where is the human?");

	std::cout << "cat brain idea[0]: " << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << "copyCat brain idea[0]: " << copyCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "operatorCopyCat brain idea[0]: " << operatorCopyCat.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n----------Done----------\n\n";
	return 0;
}