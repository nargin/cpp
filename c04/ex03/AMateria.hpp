/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:07:34 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/20 18:23:49 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		type;

	public:
		AMateria( void ){
		};
		AMateria(std::string const &type){
			this->type = type;
		};
		AMateria(AMateria const &amateria){
			*this = amateria;
		};

		virtual ~AMateria(){
		};

		AMateria	&operator = (AMateria const &amateria){
			if (this != &amateria)
				this->type = amateria.getType();
			return (*this);
		};

		std::string const & getType() const{
			return (this->type);
		};
		void use(ICharacter& target){
			if (this->type == "ice")
				std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
			else if (this->type == "cure")
				std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
		};
		virtual AMateria* clone() const = 0;
};

#endif