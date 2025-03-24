/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:01:41 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/24 10:01:44 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * Cross product for checking the point position.
 * To check whether a point P is on the line of AB
 * Here create two vectors, PA=(a.x - p.x, a.y - p.y) and PB=(b.x - p.x, b.y - p.y);
 * Then the cross production of these two vector is PA*PB=(a.x - p.x, a.y - p.y) * (b.y - p.y, b.x - p.x)
 * = ((a.x-p.x)*(b.y-p.y) -  (b.x-p.x)*(a.y-p.y))
 * 
 * 
 */
Fixed	edgePoint(const Point& a, const Point& b, const Point& point)
{
	return ((a.getX() - point.getX()) * (b.getY() - point.getY()) - (b.getX() - point.getX()) * (a.getY() - point.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed edgeAB = edgePoint(a, b, point);
	Fixed edgeBC = edgePoint(b, c, point);
	Fixed edgeCA = edgePoint(c, a, point);

	// debug info
	//std::cout << point.getX() << std::endl;
	//std::cout << point.getY() << std::endl;
	//std::cout << "edgeABP: " << edgeAB << std::endl;
	//std::cout << "edgeBCP: " << edgeBC << std::endl;
	//std::cout << "edgeCAP: " << edgeCA << std::endl;

	// If P is on the line of AB, the result would be 0
	bool onEdge = (edgeAB == 0 || edgeBC == 0 || edgeCA == 0);
	// And result > 0 and < 0 means P is at the left or right of a vector, if to all edge, P is at the same side, means inside these area.
	bool inside = ((edgeAB > 0 && edgeBC > 0 && edgeCA > 0) || (edgeAB < 0 && edgeBC < 0 && edgeCA < 0));
	return (inside && !onEdge);
}
