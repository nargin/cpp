/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:15:02 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:18:58 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void) {
			std::cout << "WrongAnimal constructor called" << std::endl;
		};
		WrongAnimal(WrongAnimal const & src) {
			std::cout << "WrongAnimal copy constructor called" << std::endl;
			*this = src;
		};
		virtual ~WrongAnimal(void) {
			std::cout << "WrongAnimal destructor called" << std::endl;
		};
		WrongAnimal &	operator=(WrongAnimal const & rhs) {
			if (this != &rhs)
				this->_type = rhs.getType();
			return *this;
		};
		std::string		getType(void) const {
			return !this->_type.empty() ? this->_type : "WrongAnimal";
		};
		void			makeSound(void) const {
			std::cout << "WrongAnimal sound" << std::endl;
		};
	protected:
		std::string	_type;
};

#endif