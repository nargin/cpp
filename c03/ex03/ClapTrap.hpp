/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:14:53 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 17:06:18 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
    public:
        ClapTrap(void) {
            std::cout << "ClapTrap created" << std::endl;
        };
        ClapTrap(std::string name) {
            std::cout << "ClapTrap " << name << " created" << std::endl;
            this->_name = name;
            this->_hitPoints = 100;
            this->_energyPoints = 50;
            this->_attackDamage = 20;
        };
        
        ClapTrap(ClapTrap const& src) {
            std::cout << "ClapTrap " << src._name << " created by copy" << std::endl;
            *this = src;
            this->_name += "_copy";
        };

        ~ClapTrap(void) {
            std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
        };

        ClapTrap&	operator=(ClapTrap const& src);

        void		attack(std::string const& target);
        void		takeDamage(unsigned int amount);
        void		beRepaired(unsigned int amount);

    protected:
        std::string	_name;
        int			_hitPoints;
        int			_energyPoints;
        int			_attackDamage;
};

#endif