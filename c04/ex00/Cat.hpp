/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:34 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 18:23:02 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void) {
			std::cout << "Cat constructor called" << std::endl;
			this->_type = "Cat";
		};
		Cat(Cat const & src) {
			std::cout << "Cat copy constructor called" << std::endl;
			*this = src;
		};
		virtual ~Cat(void) {
			std::cout << "Cat destructor called" << std::endl;
		};
		Cat &	operator=(Cat const & rhs) {
			if (this != &rhs)
				this->_type = rhs.getType();
			return *this;
		};
		virtual void	makeSound(void) const {
			std::cout << "Miaouuuuuu" << std::endl;
		};
};

#endif