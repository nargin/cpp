/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:47:07 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 15:50:19 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public :
		FragTrap(std::string name) : ClapTrap(name) {
			std::cout << "FragTrap " << name << " created" << std::endl;
			this->_hitPoints = 100;
			this->_energyPoints = 100;
			this->_attackDamage = 30;
		};
		FragTrap(FragTrap const& src) : ClapTrap(src) {
			std::cout << "FragTrap " << src._name << " created by copy" << std::endl;
			*this = src;
			this->_name += "_copy";
		};
		~FragTrap(void) {
			std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
		};

		FragTrap&	operator=(FragTrap const& src);

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		highFivesGuys(void);
	private :
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif