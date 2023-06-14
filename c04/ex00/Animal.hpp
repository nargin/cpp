/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:20:56 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:36:50 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	public:
		Animal(void) {
			std::cout << "Animal constructor called" << std::endl;
		};
		Animal(Animal const & src) {
			std::cout << "Animal copy constructor called" << std::endl;
			*this = src;
		};
		virtual ~Animal(void) {
			std::cout << "Animal destructor called" << std::endl;
		};
		Animal &	operator=(Animal const & rhs) {
			if (this != &rhs)
				this->_type = rhs.getType();
			return *this;
		};
		virtual void	makeSound(void) const {
		};
		std::string		getType(void) const {
			return !this->_type.empty() ? this->_type : "Animal";
		};
	protected:
		std::string	_type;
};

#endif