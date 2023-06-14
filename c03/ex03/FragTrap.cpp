/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:45:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 15:48:41 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::attack(std::string const& target) {
	std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FragTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FragTrap " << this->_name << " be repaired of " << amount << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " ask for high fives!" << std::endl;
}