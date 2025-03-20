/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:53:06 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 12:53:08 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ReplaceFile.hpp"

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong args. Please enter [./replace filename s1 s2]\n";
		return 1;
	}
	std::string	filename = argv[1];
	std::string	s1  = argv[2];
	std::string	s2 = argv[3];
	ReplaceFile	replaceFile(filename, s1, s2, "");
	if (replaceFile.replace())
		return 1;
	return 0;
}
