/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:44:43 by robin             #+#    #+#             */
/*   Updated: 2023/06/13 14:56:12 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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

float Point::getX(void) const
{
    return this->_x.toFloat();
}

float Point::getY(void) const
{
    return this->_y.toFloat();
}

Point & Point::operator=(Point const & rhs)
{
    if (this != &rhs)
    {
        this->_x = rhs.getX();
        this->_y = rhs.getY();
    }
    return *this;
}