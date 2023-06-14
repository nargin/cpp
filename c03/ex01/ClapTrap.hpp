/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:22:37 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 01:36:01 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    public:
        ClapTrap(std::string name) {
            this->_name = name;
            this->_hitPoints = 10;
            this->_energyPoints = 10;
            this->_attackDamage = 0;
            std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
        };
        
        ClapTrap(ClapTrap const& src) {
            *this = src;
            this->_name += "_copy";
            std::cout << "ClapTrap " << this->_name << " is copied" << std::endl;
        };
        
        ~ClapTrap(void) {
            std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
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