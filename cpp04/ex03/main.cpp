/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:52:37 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/28 14:52:38 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define RED "\033[31m"
#define WHITE "\033[0m"

void subjectTest()
{
	IMateriaSource* src = nullptr;
	ICharacter* me = nullptr;
	AMateria* tmp = nullptr;
	ICharacter* bob = nullptr;

	try
	{
		src = new MateriaSource();
		src->learnMateria(new Ice());
		//throw std::bad_alloc();
		src->learnMateria(new Cure());

		me = new Character("me");
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete bob;
		delete me;
		delete src;
		return ;
	}	
}

void myTest()
{
	IMateriaSource* src = nullptr;
	AMateria* ice = nullptr;
	AMateria* cure = nullptr;
	AMateria* tmp = nullptr;
	ICharacter* me = nullptr;
	ICharacter* bob = nullptr;

	try
	{
		src = new MateriaSource();
		ice = new Ice();
		me = new Character("me");
		//throw std::bad_alloc();
		cure = new Cure();
		bob = new Character("bob");
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete bob;
		delete me;
		delete cure;
		delete ice;
		delete src;
		return ;
	}

	try
	{
		std::cout << "\n----------Materia test----------\n\n";
		std::cout << "\n---empty materia---\n\n";
		src->learnMateria(nullptr);
		src->printMateria();
		std::cout << "\n---learnMateria---\n\n";
		src->learnMateria(ice);
		src->learnMateria(cure);
		src->learnMateria(ice);
		src->learnMateria(cure);
		src->learnMateria(cure);
		src->learnMateria(nullptr);
		//print inventory
		std::cout << "learnMateria result:\n";
		src->printMateria();
		
		std::cout << "\n---unknowType Materia---\n\n";
		tmp = src->createMateria("unknow");
		me->equip(tmp);
		me->use(0, *bob);
		me->printCharacter();

		std::cout << "\n---empty Materia---\n\n";
		tmp = src->createMateria("");
		me->equip(tmp);
		me->use(0, *bob);
		me->printCharacter();

		std::cout << "\n----------equip & unequip----------\n\n";
		std::cout << "\n---equip ice---\n\n";
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		me->printCharacter();
		std::cout << "\n---equip cure---\n\n";
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		me->printCharacter();

		std::cout << "\n---unequip---\n\n";
		me->unequip(0);
		me->unequip(1);
		me->use(0, *bob);
		me->use(1, *bob);
		me->printCharacter();

		std::cout << "\n---equip all---\n\n";
		for (int i = 0; i < 4; i++)
		{
			if (i < 2)
			{
				tmp = src->createMateria("ice");
				me->equip(tmp);
			}
			else
			{
				tmp = src->createMateria("cure");
				me->equip(tmp);
			}
		}
		me->printCharacter();

		std::cout << "\n---equip more---\n\n";
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->printCharacter();

		std::cout << "\n---use all---\n\n";
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		std::cout << "\n---use others---\n\n";
		me->use(-1, *bob);
		me->use(4, *bob);

		std::cout << "\n---unequip all---\n\n";
		std::cout << "Before unequip:" << std::endl;
		me->printCharacter();
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		std::cout << "After unequip:" << std::endl;
		me->printCharacter();

		std::cout << "\n---unequip others---\n\n";
		me->unequip(2);
		me->unequip(-1);
		me->unequip(4);
		me->printCharacter();
		
		delete bob;
		delete me;
		delete src;
		delete tmp;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << std::endl << WHITE;
		delete bob;
		delete me;
		delete src;
		delete tmp;
		return ;
	}
}

int main()
{
	std::cout << "\n----------SubjectTest----------\n\n";
	subjectTest();

	std::cout << "\n----------MyTest----------\n\n";	
	myTest();

	std::cout << "\n----------Done----------\n\n";

	return 0;
}
