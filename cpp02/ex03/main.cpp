/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:00:52 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/24 10:00:53 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void	checkPoint(const Point a, const Point b, const Point c, const Point test, const std::string testname)
{
	std::cout << "[ " << testname << " ]:\n";
	if (bsp(a, b, c, test))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
}

int	main(void)
{
	// triangle points
	Point	a(0.0f, 0.0f);
	Point	b(1.0f, 0.0f);
	Point	c(0.0f, 1.0f);
	
	// Test: close to, and on a edge
	Point	test1(0.49f, 0.49f);
	Point	test2(0.50f, 0.50f);
	Point	test3(0.51f, 0.51f);

	// Test: close to, and on one triangle point
	Point	test4(0.01f, 0.01f);
	Point	test5(0.0f, 0.0f);
	Point	test6(-0.01f, -0.01f);
	
	// Test: outside
	Point	test7(-0.5f, -0.5f);
	Point	test8(0.5f, 1.5f);
	Point	test9(128.0f, 2147483648.0f);

	checkPoint(a, b, c, test1, "test1");
	checkPoint(a, b, c, test2, "test2");
	checkPoint(a, b, c, test3, "test3");
	checkPoint(a, b, c, test4, "test4");
	checkPoint(a, b, c, test5, "test5");
	checkPoint(a, b, c, test6, "test6");
	checkPoint(a, b, c, test7, "test7");
	checkPoint(a, b, c, test8, "test8");
	checkPoint(a, b, c, test9, "test9");
	
	return 0;
}
