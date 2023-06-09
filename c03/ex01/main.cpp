/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:21:58 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 15:41:21 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Clappy");
    ScavTrap scavTrap("Cafard");

    clapTrap.attack("China");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);

    scavTrap.attack("Cuba");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    return (0);
}