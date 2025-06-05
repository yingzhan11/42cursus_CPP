/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:31 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:01:32 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string> //std::string
#include <cctype> //std::isprint, std::isdigit
#include <limits> //std::numeric_limits
#include <iomanip> //std::setprecission
#include <exception> //trycatch std::out_of_range

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOFLOAT,
	PSEUDODOUBLE,
	UNKNOWN
};


/**
 * purely static utility class, without instantiating any object
 * use delete to to disable a function
 */ 
class ScalarConverter {
	private:
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		~ScalarConverter(void) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;

	public:
		static void convert(const std::string &str);
};
