/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:28:49 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:38:34 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain(void) {
			std::cout << "Brain constructor called" << std::endl;
		};
		Brain(Brain const & src) {
			std::cout << "Brain copy constructor called" << std::endl;
			*this = src;
		};
		~Brain(void) {
			std::cout << "Brain destructor called" << std::endl;
		};
		Brain &	operator=(Brain const & rhs) {
			if (this != &rhs)
				for (int i = 0; i < 100; i++)
					this->_ideas[i] = rhs.getIdea(i);
			return *this;
		};
		std::string		getIdea(int i) const {
			return this->_ideas[i];
		};
		void			setIdea(int i, std::string idea) {
			this->_ideas[i] = idea;
		};
		void			printIdeas(void) const {
			for (int i = 0; i < 100; i++)
				std::cout << this->_ideas[i] << std::endl;
		};
	private:
		std::string		_ideas[100];
};

#endif