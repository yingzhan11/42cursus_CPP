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

#define RED "\033[31m"

void	basicTest()
{

}


int main()
{
	//const Animal* animal = nullptr;
    const Animal* dog = nullptr;
    const Animal* cat = nullptr;
    const WrongAnimal* wrongAnimal = nullptr;
    const WrongAnimal* wrongCat = nullptr;

	try
	{
		std::cout << "\n----------NormalTest----------\n\n";
		//animal = new Animal();
		dog = new Dog();
		cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		//animal->makeSound();

		delete dog;
		delete cat;
		//delete animal;

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
		//delete animal;
		delete wrongCat;
		delete wrongAnimal;

		return ;
	}
	
	
	//std::cout << "\n---Copy---\n\n";
	//Animal	bird;
	//Animal	copyBird(bird);
	//Animal	operatorCopyBird = bird;
	//std::cout << "\n---Default type---\n\n";
	//std::cout << "bird type: " << bird.getType() << std::endl;
	//std::cout << "copyBird type: " << copyBird.getType() << std::endl;
	//std::cout << "operatorCopyBird type: " << operatorCopyBird.getType() << std::endl;
		
	//std::cout << "\n---Set a new type---\n\n";
	//copyBird.setType("Black Bird");
	//operatorCopyBird.setType("Red bird");

	//std::cout << "bird type: " << bird.getType() << std::endl;
	//std::cout << "copyBird type: " << copyBird.getType() << std::endl;
	//std::cout << "operatorCopyBird type: " << operatorCopyBird.getType() << std::endl;

	//std::cout << "\n----------Done----------\n\n";

	
	return 0;
}