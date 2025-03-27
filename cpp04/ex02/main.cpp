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

int main()
{
	std::cout << "\n----------NormalTest----------\n\n";
	//const AAnimal* animal = new AAnimal();
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	//animal->makeSound();

	delete dog;
	dog = nullptr;
	delete cat;
	cat = nullptr;
	//delete animal;
	//animal = nullptr;

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

	std::cout << "\n----------Done----------\n\n";

	return 0;
}