/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:44:43 by robin             #+#    #+#             */
/*   Updated: 2023/06/13 17:56:28 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0)
{
	
}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY())
{
	
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	
}

Point::~Point(void)
{
	
}

Point & Point::operator=(Point const & rhs)
{
	_x = rhs.getX();
	_y = rhs.getY();
	return *this;
}

float Point::getX(void) const {
	return this->_x.toFloat();
}

float Point::getY(void) const {
	return this->_y.toFloat();
}

std::ostream & operator<<(std::ostream & o, Point const & rhs)
{
	o << "Point(" << rhs.getX() << ", " << rhs.getY() << ")";
	return o;
}