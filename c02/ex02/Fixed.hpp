/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:30:13 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/12 23:46:48 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
		
		Fixed			operator+(Fixed const & lhs, Fixed const & rhs);
		Fixed			operator-(Fixed const & lhs, Fixed const & rhs);
		Fixed			operator*(Fixed const & lhs, Fixed const & rhs);
		Fixed			operator/(Fixed const & lhs, Fixed const & rhs);
		
		Fixed			&operator++(void);
		Fixed			operator++(int);
		Fixed			&operator--(void);
		Fixed			operator--(int);
		static Fixed			&min(Fixed & lhs, Fixed & rhs);
		static Fixed			&max(Fixed & lhs, Fixed & rhs);
		static Fixed const		&min(Fixed const & lhs, Fixed const & rhs);
		static Fixed const		&max(Fixed const & lhs, Fixed const & rhs);

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

bool			operator>(Fixed const & lhs, Fixed const & rhs);
bool			operator<(Fixed const & lhs, Fixed const & rhs);
bool			operator>=(Fixed const & lhs, Fixed const & rhs);
bool			operator<=(Fixed const & lhs, Fixed const & rhs);
bool			operator==(Fixed const & lhs, Fixed const & rhs);
bool			operator!=(Fixed const & lhs, Fixed const & rhs);

#endif