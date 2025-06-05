/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:05:22 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:05:24 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(void)
{
    std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;

    std::cout << BLUE << "\n----------Vector Test----------\n\n" << WHITE;
    std::vector<int> testVec = {5, 15, 25, 35, 45, 55};
    try {
        auto it = easyfind(testVec, 25);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        auto it = easyfind(testVec, 20);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n----------List Test----------\n\n" << WHITE;
    std::list<int> testLst = {50, 150, 250, 350, 450, 550};
    try {
        auto it = easyfind(testLst, 550);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        auto it = easyfind(testLst, 20);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n----------Deque Test----------\n\n" << WHITE;
    std::list<int> testDeq = {75, -55, 35, -25, 5, -15};
    try {
        auto it = easyfind(testDeq, -25);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        auto it = easyfind(testDeq, 20);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n----------Empty Test----------\n\n" << WHITE;
    std::array<int, 0> testArr = {};
    try {
        auto it = easyfind(testArr, -25);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n----------Testing Done----------\n\n" << WHITE;
	return (0);
}
