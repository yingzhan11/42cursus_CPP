/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:28 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:02:29 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime> //std::time
#include "Base.hpp"
#include "identify.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(void)
{
	std::srand(std::time(0));
	std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	for (int i = 0; i < 6; i++)
	{
		std::cout << BLUE << "\n---Test: " << i + 1 << "---\n\n" << WHITE;
		Base* testBase = generate();
		std::cout << BLUE << "Identify ptr: " << WHITE;
		identify(testBase);
		std::cout << BLUE << "Identify ref: " << WHITE;
		identify(*testBase);
		delete testBase;
		testBase = nullptr;
	}
	std::cout << BLUE  << "\n----------Testing Done----------\n\n" << WHITE;
	return (0);
}
