/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:53 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 15:30:40 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap&	ScavTrap::operator=(ScavTrap const& src) {
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return *this;
}

void		ScavTrap::attack(std::string const& target) {
    std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "ScavTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount) {
    std::cout << "ScavTrap " << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
}

void		ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
}