/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:59 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 03:12:26 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class	ScavTrap
{
    public:
        ScavTrap(std::string name) {
            std::cout << "ScavTrap " << name << " created" << std::endl;
            this->_name = name;
            this->_hitPoints = 100;
            this->_energyPoints = 50;
            this->_attackDamage = 20;
        };
        
        ScavTrap(ScavTrap const& src) {
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

    private:
        std::string	_name;
        int			_hitPoints;
        int			_energyPoints;
        int			_attackDamage;
};

#endif