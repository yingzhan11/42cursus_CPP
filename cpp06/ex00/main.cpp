/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:11 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:01:13 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		const std::string input(argv[1]);
		ScalarConverter::convert(input);
		return (0);
	}

	std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	
	std::cout << BLUE << "\n----------Char Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Input: [a]---\n\n" << WHITE;
	ScalarConverter::convert("a");
	std::cout << BLUE << "\n---Input: [A]---\n\n" << WHITE;
	ScalarConverter::convert("A");
	std::cout << BLUE << "\n---Input: [0]---\n\n" << WHITE;
	ScalarConverter::convert("0");
	std::cout << BLUE << "\n---Input: [ ]---\n\n" << WHITE;
	ScalarConverter::convert(" ");
	std::cout << BLUE << "\n---Input: [\\n]---\n\n" << WHITE;
	ScalarConverter::convert("\n");
	std::cout << BLUE << "\n---Input: [\\t]---\n\n" << WHITE;
	ScalarConverter::convert("\t");
	std::cout << BLUE << "\n---Input: [+]---\n\n" << WHITE;
	ScalarConverter::convert("+");
	std::cout << BLUE << "\n---Input: [&]---\n\n" << WHITE;
	ScalarConverter::convert("&");
	std::cout << BLUE << "\n---Input: [string]---\n\n" << WHITE;
	ScalarConverter::convert("string");
	std::cout << BLUE << "\n---Input: [+++]---\n\n" << WHITE;
	ScalarConverter::convert("+++");
	std::cout << BLUE << "\n---Input: [😀]--\n\n" << WHITE;	
	ScalarConverter::convert("😀");

	std::cout << BLUE << "\n----------Int Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Input: [4]---\n\n" << WHITE;
	ScalarConverter::convert("4");
	std::cout << BLUE << "\n---Input: [+42]---\n\n" << WHITE;
	ScalarConverter::convert("+42");
	std::cout << BLUE << "\n---Input: [-42]---\n\n" << WHITE;
	ScalarConverter::convert("-42");
	std::cout << BLUE << "\n---Input: [4242]---\n\n" << WHITE;
	ScalarConverter::convert("4242");
	std::cout << BLUE << "\n---Input: [INT_MAX]---\n\n" << WHITE;
	ScalarConverter::convert("2147483647");
	std::cout << BLUE << "\n---Input: [INT_MIN]---\n\n" << WHITE;
	ScalarConverter::convert("-2147483648");
	std::cout << BLUE << "\n---Input: [INT_MAX + 1]---\n\n" << WHITE;
	ScalarConverter::convert("2147483648");
	std::cout << BLUE << "\n---Input: [INT_MIN - 1]---\n\n" << WHITE;
	ScalarConverter::convert("-2147483649");
	std::cout << BLUE << "\n---Input: [++42]---\n\n" << WHITE;
	ScalarConverter::convert("++42");
	std::cout << BLUE << "\n---Input: [+42a]---\n\n" << WHITE;
	ScalarConverter::convert("+42a");

	std::cout << BLUE << "\n----------Float Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Input: [0.0f]---\n\n" << WHITE;
	ScalarConverter::convert("0.0f");
	std::cout << BLUE << "\n---Input: [+4.2f]---\n\n" << WHITE;
	ScalarConverter::convert("+4.2f");
	std::cout << BLUE << "\n---Input: [-42.0f]---\n\n" << WHITE;
	ScalarConverter::convert("-42.0f");
	std::cout << BLUE << "\n---Input: [424.2f]---\n\n" << WHITE;
	ScalarConverter::convert("424.2f");
	std::cout << BLUE << "\n---Input: [nanf]---\n\n" << WHITE;
	ScalarConverter::convert("nanf");
	std::cout << BLUE << "\n---Input: [-inff]---\n\n" << WHITE;
	ScalarConverter::convert("-inff");
	std::cout << BLUE << "\n---Input: [+inff]---\n\n" << WHITE;
	ScalarConverter::convert("+inff");
	std::cout << BLUE << "\n---Input: [FLOAT_MAX]---\n\n" << WHITE;
	float floatMax = std::numeric_limits<float>::max();
	std::string floatMaxStr = std::to_string(floatMax);
	ScalarConverter::convert(floatMaxStr);
	std::cout << BLUE << "\n---Input: [FLOAT_MIN]---\n\n" << WHITE;
	float floatMin = std::numeric_limits<float>::lowest();
	std::string floatMinStr = std::to_string(floatMin);
	ScalarConverter::convert(floatMinStr);
	std::cout << BLUE << "\n---Input: [FLOAT_OVERFLOW]---\n\n" << WHITE;
	std::string floatOverFlowStr = std::to_string(floatMax * 2.0f);
	ScalarConverter::convert(floatOverFlowStr);
	std::cout << BLUE << "\n---Input: [FLOAT_OVERFLOW_NEG]---\n\n" << WHITE;
	std::string floatNegOverFlowStr = std::to_string(floatMin * 2.0f);
	ScalarConverter::convert(floatNegOverFlowStr);
	std::cout << BLUE << "\n---Input: [42.f]---\n\n" << WHITE;
	ScalarConverter::convert("42.f");
	std::cout << BLUE << "\n---Input: [42f.]---\n\n" << WHITE;
	ScalarConverter::convert("42f.");
	std::cout << BLUE << "\n---Input: [.42f]---\n\n" << WHITE;
	ScalarConverter::convert(".42f");
	std::cout << BLUE << "\n---Input: [42.4.2f]---\n\n" << WHITE;
	ScalarConverter::convert("42.4.2f");
	std::cout << BLUE << "\n---Input: [4.2ff]---\n\n" << WHITE;
	ScalarConverter::convert("4.2ff");

	std::cout << BLUE << "\n----------Double Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Input: [0.0]---\n\n" << WHITE;
	ScalarConverter::convert("0.0");
	std::cout << BLUE << "\n---Input: [+4.2]---\n\n" << WHITE;
	ScalarConverter::convert("+4.2");
	std::cout << BLUE << "\n---Input: [-42.0]---\n\n" << WHITE;
	ScalarConverter::convert("-42.0");
	std::cout << BLUE << "\n---Input: [0.42]---\n\n" << WHITE;
	ScalarConverter::convert("0.42");
	std::cout << BLUE << "\n---Input: [424.2]---\n\n" << WHITE;
	ScalarConverter::convert("424.2");
	std::cout << BLUE << "\n---Input: [nan]---\n\n" << WHITE;
	ScalarConverter::convert("nan");
	std::cout << BLUE << "\n---Input: [-inf]---\n\n" << WHITE;
	ScalarConverter::convert("-inf");
	std::cout << BLUE << "\n---Input: [+inf]---\n\n" << WHITE;
	ScalarConverter::convert("+inf");
	std::cout << BLUE << "\n---Input: [DOUBLE_MAX]---\n\n" << WHITE;
	double doubleMax = std::numeric_limits<double>::max();
	std::string doubleMaxStr = std::to_string(doubleMax);
	ScalarConverter::convert(doubleMaxStr);
	std::cout << BLUE << "\n---Input: [DOUBLE_MIN]---\n\n" << WHITE;
	double doubleMin = std::numeric_limits<double>::lowest();
	std::string doubleMinStr = std::to_string(doubleMin);
	ScalarConverter::convert(doubleMinStr);
	std::cout << BLUE << "\n---Input: [DOUBLE_OVERFLOW]---\n\n" << WHITE;
	std::string doubleOverFlowStr = std::to_string(doubleMax * 2.0);
	ScalarConverter::convert(doubleOverFlowStr);
	std::cout << BLUE << "\n---Input: [DOUBLE_OVERFLOW_NEG]---\n\n" << WHITE;
	std::string doubleNegOverFlowStr = std::to_string(doubleMin * 2.0);
	ScalarConverter::convert(doubleNegOverFlowStr);
	std::cout << BLUE << "\n---Input: [214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647.0]---\n\n" << WHITE;
	ScalarConverter::convert("214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647.0");
	std::cout << BLUE << "\n---Input: [42.]---\n\n" << WHITE;
	ScalarConverter::convert("42.");
	std::cout << BLUE << "\n---Input: [.42]---\n\n" << WHITE;
	ScalarConverter::convert(".42");
	std::cout << BLUE << "\n---Input: [42.4.2]---\n\n" << WHITE;
	ScalarConverter::convert("42.4.2");
	std::cout << BLUE << "\n---Input: [42..42]---\n\n" << WHITE;
	ScalarConverter::convert("42..42");

	std::cout << BLUE << "\n----------Testing Done----------\n\n" << WHITE;
	return (0);
}
