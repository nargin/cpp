/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:21:58 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 16:58:49 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int     main(void)
{
    DiamondTrap     diamondTrap("DiamondTrap");

    diamondTrap.whoAmI();
    diamondTrap.attack("Robin");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(10);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();
    return (0);
}