/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:01:32 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/24 10:01:33 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(x), _y(y){}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y){}

Point& Point::operator=(const Point& copy)
{
	(void)copy;
	return (*this);
}

Point::~Point(){}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
