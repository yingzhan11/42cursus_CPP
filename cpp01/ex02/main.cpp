/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:38:46 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/18 13:38:47 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Pointer and reference
int	main(void)
{
	std::string	str1 = "HI THIS IS BRAIN";
	std::string* strPTR = &str1;
	std::string& strREF = str1;

	std::cout << "[ Address ]\n";
	std::cout << "str address: " << &str1 << std::endl;
	std::cout << "strPTR address: " << strPTR << std::endl;
	std::cout << "strREF address: " << &strREF << std::endl;
	std::cout << "[ Value ]\n";
	std::cout << "str value: " << str1 << std::endl;
	std::cout << "strPTR value: " << *strPTR << std::endl;
	std::cout << "strREF value: " << strREF << std::endl;
	std::cout << std::endl;

	// Reassign PTR and REF
	std::string str2 = "SECOND BRAIN";
	strPTR = &str2;
	strREF = str2;
	std::cout << "[ Address ]\n";
	std::cout << "str2 address: " << &str2 << std::endl;
	std::cout << "strPTR address: " << strPTR << std::endl;
	std::cout << "strREF address: " << &strREF << std::endl;
	std::cout << "[ Value ]\n";
	std::cout << "str value: " << str2 << std::endl;
	std::cout << "strPTR value: " << *strPTR << std::endl;
	std::cout << "strREF value: " << strREF << std::endl;
	std::cout << std::endl;

	// Change the value
	*strPTR = "CHANGE A NEW BRAIN";
	std::cout << "[ Change by PTR ]\n";
	std::cout << "strPTR value: " << *strPTR << std::endl;
	std::cout << "str value: " << str2 << std::endl;
	strREF = "ANOTHER BRAIN";
	std::cout << "[ Change by REF ]\n";
	std::cout << "strREF value: " << strREF << std::endl;
	std::cout << "str1 value: " << str1 << std::endl;
	std::cout << "str2 value: " << str2 << std::endl;

	return 0;
}
