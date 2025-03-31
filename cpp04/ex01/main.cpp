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
#define RED "\033[31m"

void	basicTest()
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
		//throw std::bad_alloc();
		cat = new Cat();
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete dog;
		delete cat;
		delete animal;
		return ;
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
	//std::cout << "\n----------BasicTest----------\n\n";
	//basicTest();
	
	std::cout << "\n----------AnimalArrayTest----------\n\n";
	std::cout << "\n---Constructor---\n\n";
	const Animal	*animal[AMOUNT];
	int i = 0;
	try {
		for (; i < AMOUNT; i++)
		{
			animal[i] = nullptr;
			if (i < AMOUNT / 2)
				animal[i] = new Dog();
			else
			{
				animal[i] = new Cat();
				//throw std::bad_alloc();
			}
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
	
	std::cout << "\n----------CatDeepCopyTest----------\n\n";
	try {
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
	}  catch (const std::bad_alloc& e) {
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		return 1;
	}

	std::cout << "\n----------DogDeepCopyTest----------\n\n";
	try {
		std::cout << "\n---Copy---\n\n";
		Dog	dog;
		Dog	copyDog(dog);
		Dog	operatorCopyDog = dog;
		std::cout << "\n---Default idea---\n\n";
		std::cout << "dog brain idea[0]: " << dog.getBrain()->getIdea(0) << std::endl;
		std::cout << "copyDog brain idea[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "operatorCopyDog brain idea[0]: " << operatorCopyDog.getBrain()->getIdea(0) << std::endl;
		
		std::cout << "\n---Set a new idea---\n\n";
		copyDog.getBrain()->setIdea(0, "Woooooof~~~~");
		operatorCopyDog.getBrain()->setIdea(0, "Where is the human?");

		std::cout << "dog brain idea[0]: " << dog.getBrain()->getIdea(0) << std::endl;
		std::cout << "copyDog brain idea[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "operatorCopyDog brain idea[0]: " << operatorCopyDog.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n----------Done----------\n\n";
	}  catch (const std::bad_alloc& e) {
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		return 1;
	}
	
	return 0;
}