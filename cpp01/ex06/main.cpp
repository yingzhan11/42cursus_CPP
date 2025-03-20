/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:11:53 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 15:11:54 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong args. Please enter [./harlFilter <string>]\n";
		return 1;
	}

	Harl	harl;
	harl.complain(argv[1]);
	return 0;
}
