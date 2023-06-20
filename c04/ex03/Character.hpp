/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:08:43 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/20 18:23:56 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;


class Character : public ICharacter
{
	private:
		std::string		name;
		int				count;
		AMateria		*inventory[4];

	public:
		Character( void ){
			this->name = "default";
			this->count = 0;
			for (int i = 0; i < 4; i++)
				this->inventory[i] = NULL;
		};
		Character(std::string const &name){
			this->name = name;
			this->count = 0;
			for (int i = 0; i < 4; i++)
				this->inventory[i] = NULL;
		};
		Character(Character const &Character){
			*this = Character;
		};

		~Character( void ){
		};

		Character	&operator = (Character const &character){
			if (this != &character)
			{
				this->name = character.name;
				this->count = character.count;
				for (int i = 0; i < 4; i++)
					this->inventory[i] = character.inventory[i];
			}
			return (*this);
		};

		std::string const & getName() const{
			return (this->name);
		};
		void equip(AMateria* m){
			if (this->count < 4)
			{
				this->inventory[this->count] = m;
				this->count++;
			}
		};
		void unequip(int idx){
			if (idx >= 0 && idx < 4)
				this->inventory[idx] = NULL;
		};
		void use(int idx, ICharacter& target){
			if (idx >= 0 && idx < 4)
				this->inventory[idx]->use(target);
		};
};

#endif