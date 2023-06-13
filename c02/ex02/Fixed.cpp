/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:30:52 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/12 23:50:43 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{

}

Fixed::Fixed(Fixed const & src)
{
	*this = src;

}

Fixed::Fixed(int const n): _rawBits(n << Fixed::_fractionalBits)
{

}

Fixed::Fixed(float const n): _rawBits(roundf(n * (1 << Fixed::_fractionalBits)))
{

}

Fixed::~Fixed(void)
{

}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	this->_rawBits = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_rawBits / (1 << Fixed::_fractionalBits);
}

int		Fixed::toInt(void) const
{
	return this->_rawBits >> Fixed::_fractionalBits;
}


std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool			operator>(Fixed const & lhs, Fixed const & rhs)
{
	return lhs.getRawBits() > rhs.getRawBits();
}

bool			operator<(Fixed const & lhs, Fixed const & rhs)
{
	return lhs.getRawBits() < rhs.getRawBits();
}

bool			operator>=(Fixed const & lhs, Fixed const & rhs)
{
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool			operator<=(Fixed const & lhs, Fixed const & rhs)
{
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool			operator==(Fixed const & lhs, Fixed const & rhs)
{
	return lhs.getRawBits() == rhs.getRawBits();
}

bool			operator!=(Fixed const & lhs, Fixed const & rhs)
{
	return lhs.getRawBits() != rhs.getRawBits();
}

Fixed			Fixed::operator+(Fixed const & rhs)
{
	return Fixed(toFloat() + rhs.toFloat());
}

Fixed			Fixed::operator-(Fixed const & rhs)
{
	return Fixed(toFloat() - rhs.toFloat());
}

Fixed			Fixed::operator*(Fixed const & rhs)
{
	return Fixed(toFloat() * rhs.toFloat());
}

Fixed			Fixed::operator/(Fixed const & rhs)
{
	return Fixed(toFloat() / rhs.toFloat());
}

Fixed &			Fixed::operator++(void)
{
	this->_rawBits++;
	return *this;
}

Fixed			Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(*this);
	return tmp;
}

Fixed &			Fixed::operator--(void)
{
	this->_rawBits--;
	return *this;
}

Fixed			Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(*this);
	return tmp;
}

Fixed &			Fixed::min(Fixed & lhs, Fixed & rhs)
{
	return (lhs < rhs) ? lhs : rhs;
}

Fixed const &	Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs < rhs) ? lhs : rhs;
}

Fixed &			Fixed::max(Fixed & lhs, Fixed & rhs)
{
	return (lhs > rhs) ? lhs : rhs;
}

Fixed const &	Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs > rhs) ? lhs : rhs;
}
