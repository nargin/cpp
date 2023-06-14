/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:23:13 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:38:24 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void) {
			std::cout << "Dog constructor called" << std::endl;
			this->_type = "Dog";
			this->_brain = new Brain();
		};
		Dog(Dog const & src) {
			std::cout << "Dog copy constructor called" << std::endl;
			*this = src;
		};
		virtual ~Dog(void) {
			std::cout << "Dog destructor called" << std::endl;
			delete this->_brain;
		};
		Dog &	operator=(Dog const & rhs) {
			if (this != &rhs)
				this->_type = rhs.getType();
			return *this;
		};
		virtual void	makeSound(void) const {
			std::cout << "Wouafff" << std::endl;
		};
	private:
		Brain	*_brain;
};

#endif