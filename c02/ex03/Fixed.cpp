/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:30:52 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:23 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0) {
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

Fixed::Fixed(int const n): _rawBits(n << Fixed::_fractionalBits) {
}

Fixed::Fixed(float const n): _rawBits(roundf(n * (1 << Fixed::_fractionalBits))) {
}

Fixed::~Fixed(void) {
}

int		Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << Fixed::_fractionalBits);
}

int		Fixed::toInt(void) const {
	return this->_rawBits >> Fixed::_fractionalBits;
}


std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
