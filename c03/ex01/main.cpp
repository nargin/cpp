/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:21:58 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 03:18:06 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap    scavTrap("ScavTrap");
    ClapTrap    clapTrap("ClapTrap");

    scavTrap.attack("ClapTrap");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    std::cout << std::endl;
    clapTrap.attack("ScavTrap");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);
    std::cout << std::endl;
    return 0;
}