/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:31:07 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/20 16:05:19 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria;

class Cure : public AMateria
{
	public:
		Cure( void ){
			this->type = "cure";
		};
		Cure(Cure const &cure){
			*this = cure;
		};

		~Cure( void ){
		};

		Cure	&operator = (Cure const &cure){
			if (this != &cure)
				this->type = cure.getType();
			return (*this);
		};

		AMateria* clone() const{
			return (new Cure(*this));
		};
};

#endif