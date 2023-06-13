/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:44:25 by robin             #+#    #+#             */
/*   Updated: 2023/06/13 14:52:34 by robin            ###   ########.fr       */
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

        float getX(void) const;
        float getY(void) const;

    private:
        Fixed const _x;
        Fixed const _y;
};

#endif