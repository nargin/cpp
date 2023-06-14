/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:56:54 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 17:09:43 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
	public:
		DiamondTrap(void) : ScavTrap(), FragTrap() {
			std::cout << "DiamondTrap created" << std::endl;
		};
		DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
			std::cout << "DiamondTrap " << name << " created" << std::endl;
			this->_name = name;
			this->_hitPoints = 100;
			this->_energyPoints = 50;
			this->_attackDamage = 30;
		};
		DiamondTrap(DiamondTrap const & src) : ScavTrap(src), FragTrap(src) {
			std::cout << "DiamondTrap " << src._name << " created by copy" << std::endl;
			*this = src;
			this->_name += "_copy";
		};
		~DiamondTrap(void) {
			std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;
		};

		DiamondTrap&     operator=(DiamondTrap const & rhs);

		void            whoAmI(void);
		void            attack(std::string const & target);
		void            takeDamage(unsigned int amount);
		void            beRepaired(unsigned int amount);

	private:
		std::string     _name;
		int             _hitPoints;
		int             _energyPoints;
		int             _attackDamage;
};

#endif