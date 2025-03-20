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
	std::string	str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "strPTR address: " << strPTR << std::endl;
	std::cout << "strREF address: " << &strREF << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "strPTR value: " << *strPTR << std::endl;
	std::cout << "strREF value: " << strREF << std::endl;

	//strREF = "HI";
	//std::cout << "strREF value: " << strREF << std::endl;
	//std::cout << "str value: " << str << std::endl;
	return 0;
}
