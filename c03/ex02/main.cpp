/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:21:58 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 15:49:28 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Clappy");
    ScavTrap scavTrap("Cafard");
    FragTrap fragTrap("Fraggy");

    clapTrap.attack("China");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);

    scavTrap.attack("Cuba");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();

    fragTrap.attack("Mexico");
    fragTrap.takeDamage(10);
    fragTrap.beRepaired(10);
    fragTrap.highFivesGuys();
    return (0);
}