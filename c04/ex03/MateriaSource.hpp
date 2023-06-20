/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:09:06 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/20 16:11:13 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {
		};

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria	*_materia[4];
		int			count;
	public:
		MateriaSource( void ){
			for (int i = 0; i < 4; i++)
				this->_materia[i] = NULL;
		};
		MateriaSource(MateriaSource const &materiaSource){
			*this = materiaSource;
		};

		~MateriaSource( void ){
			for (int i = 0; i < 4; i++)
				if (this->_materia[i] != NULL)
					delete this->_materia[i];
		};

		MateriaSource	&operator = (MateriaSource const &materiaSource){
			if (this != &materiaSource)
			{
				for (int i = 0; i < 4; i++)
				{
					if (this->_materia[i] != NULL)
						delete this->_materia[i];
					this->_materia[i] = materiaSource._materia[i]->clone();
				}
			}
			return (*this);
		};

		void learnMateria(AMateria* materia){
			if (this->count < 4)
			{
				this->_materia[this->count] = materia->clone();
				this->count++;
			}
		};
		AMateria* createMateria(std::string const & type){
			for (int i = 0; i < 4; i++)
			{
				if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
					return (this->_materia[i]->clone());
			}
			return (NULL);
		};
};

#endif