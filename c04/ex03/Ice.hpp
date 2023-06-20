/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:30:15 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/20 16:05:58 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria;

class Ice : public AMateria
{
	public:
		Ice( void ){
			this->type = "ice";
		};
		Ice(Ice const &ice){
			*this = ice;
		};

		~Ice( void ){
		};

		Ice	&operator = (Ice const &ice){
			if (this != &ice)
				this->type = ice.getType();
			return (*this);
		};

		AMateria* clone() const{
			return (new Ice(*this));
		};
};

#endif