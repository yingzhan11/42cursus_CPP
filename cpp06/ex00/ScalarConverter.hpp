#pragma once

#include <iostream>
#include <string> //std::string
#include <cctype> //std::isprint, std::isdigit
#include <sstream> //std::stringstream
#include <limits> //std::numeric_limits
#include <iomanip> //std::setprecission
#include <exception>

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