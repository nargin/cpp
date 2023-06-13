/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:44:25 by robin             #+#    #+#             */
/*   Updated: 2023/06/13 17:43:14 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Point const & src);
		Point(float const x, float const y);
		~Point(void);

		Point & operator=(Point const & rhs);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed _x;
		Fixed _y;
};

std::ostream & operator<<(std::ostream & o, Point const & rhs);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif