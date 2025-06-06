#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(void) {
    std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;

    std::cout << BLUE << "\n----------Mstack Test----------\n\n" << WHITE;
	MutantStack<int> mstack;

	std::cout << BLUE << "\n---add two elements---\n\n" << WHITE;
	mstack.push(5);
	mstack.push(17);
	std::cout << BLUE  << "the top element is: " << WHITE << mstack.top() << std::endl;
	std::cout << BLUE  << "the mstack size is: " << WHITE << mstack.size() << std::endl;

	std::cout << BLUE << "\n---delete the top element---\n\n" << WHITE;
	mstack.pop();
	std::cout << BLUE  << "the top element is: " << WHITE << mstack.top() << std::endl;
	std::cout << BLUE  << "the mstack size is: " << WHITE << mstack.size() << std::endl;

	std::cout << BLUE << "\n---add more elements and test iterator---\n\n" << WHITE;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << BLUE  << "the it element is: " << WHITE;
	std::cout << *it << std::endl; //begin is the first element
	std::cout << BLUE  << "move down it: " << WHITE;
	++it;
	std::cout << *it << std::endl;
	std::cout << BLUE  << "move up it: " << WHITE;
	--it;
	std::cout << *it << std::endl;

	std::cout << BLUE  << "the ite element is: " << WHITE;
	--ite; //end is the position after last elements
	std::cout << *ite << std::endl;
	std::cout << BLUE  << "move up ite: " << WHITE;
	--ite;
	std::cout << *ite << std::endl;
	std::cout << BLUE  << "move down ite: " << WHITE;
	++ite;
	std::cout << *ite << std::endl;
	++ite; //put ite back to the end position

	std::cout << BLUE << "\n---print all elements with it---\n\n" << WHITE;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << BLUE << "\n---print all elements with ite---\n\n" << WHITE;
	it = mstack.begin();
	while (ite != it)
	{
		--ite;
		std::cout << *ite << std::endl;
	}
	
	std::cout << BLUE << "\n---Compare with normal stack---\n\n" << WHITE;
	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << BLUE << "\n----------Compare with list----------\n\n" << WHITE;
	std::list<int> lst;

	std::cout << BLUE << "\n---add two elements---\n\n" << WHITE;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << BLUE  << "the top element is: " << WHITE << lst.back() << std::endl;
	std::cout << BLUE  << "the list size is: " << WHITE << lst.size() << std::endl;

	std::cout << BLUE << "\n---delete the top element---\n\n" << WHITE;
	lst.pop_back();
	std::cout << BLUE  << "the top element is: " << WHITE << lst.back() << std::endl;
	std::cout << BLUE  << "the list size is: " << WHITE << lst.size() << std::endl;

	std::cout << BLUE << "\n---add more elements and test iterator---\n\n" << WHITE;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator itLst = lst.begin();
	std::list<int>::iterator iteLst = lst.end();

	std::cout << BLUE  << "the itLst element is: " << WHITE;
	std::cout << *itLst << std::endl;
	std::cout << BLUE  << "move down itLst: " << WHITE;
	++itLst;
	std::cout << *itLst << std::endl;
	std::cout << BLUE  << "move up itLst: " << WHITE;
	--itLst;
	std::cout << *itLst << std::endl;

	std::cout << BLUE  << "the iteLst element is: " << WHITE;
	--iteLst;
	std::cout << *iteLst << std::endl;
	std::cout << BLUE  << "move up ite: " << WHITE;
	--iteLst;
	std::cout << *iteLst << std::endl;
	std::cout << BLUE  << "move down ite: " << WHITE;
	++iteLst;
	std::cout << *iteLst << std::endl;
	++iteLst;

	std::cout << BLUE << "\n---print all elements with itLst---\n\n" << WHITE;
	while (itLst != iteLst)
	{
		std::cout << *itLst << std::endl;
		++itLst;
	}

	std::cout << BLUE << "\n---print all elements with iteLst---\n\n" << WHITE;
	itLst = lst.begin();
	while (iteLst != itLst)
	{
		--iteLst;
		std::cout << *iteLst << std::endl;
	}
	
	std::cout << BLUE << "\n----------Testing Done----------\n\n" << WHITE;
	return (0);
}
