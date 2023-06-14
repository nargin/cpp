/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:18:39 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:18:55 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void) {
			std::cout << "WrongCat constructor called" << std::endl;
			this->_type = "WrongCat";
		};
		WrongCat(WrongCat const & src) {
			std::cout << "WrongCat copy constructor called" << std::endl;
			*this = src;
		};
		virtual ~WrongCat(void) {
			std::cout << "WrongCat destructor called" << std::endl;
		};
		WrongCat &	operator=(WrongCat const & rhs) {
			if (this != &rhs)
				this->_type = rhs.getType();
			return *this;
		};
		virtual void	makeSound(void) const {
			std::cout << "WrongCat sound" << std::endl;
		};
};

#endif