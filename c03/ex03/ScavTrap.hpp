/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:59 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 17:10:42 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public :
		ScavTrap(void) : ClapTrap() {
			std::cout << "ScavTrap created" << std::endl;
		};
		ScavTrap(std::string name) : ClapTrap(name) {
			std::cout << "ScavTrap " << name << " created" << std::endl;
			this->_hitPoints = 100;
			this->_energyPoints = 50;
			this->_attackDamage = 20;
		};
		ScavTrap(ScavTrap const& src) : ClapTrap(src) {
			std::cout << "ScavTrap " << src._name << " created by copy" << std::endl;
			*this = src;
			this->_name += "_copy";
		};
		~ScavTrap(void) {
			std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
		};

		ScavTrap&	operator=(ScavTrap const& src);

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		guardGate(void);
	protected :
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif