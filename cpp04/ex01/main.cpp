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

	try
	{
		std::cout << "\n----------NormalTest----------\n\n";
		animal = new Animal();
		dog = new Dog();
		cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();

		delete dog;
		delete cat;
		delete animal;

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
		delete animal;
		delete wrongCat;
		delete wrongAnimal;

		return ;
	}
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

	std::cout << "\n----------CatDeepCopyTest----------\n\n";
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