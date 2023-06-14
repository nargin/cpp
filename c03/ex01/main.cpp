/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:21:58 by robin             #+#    #+#             */
/*   Updated: 2023/06/14 01:38:23 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("pepitos");
    ClapTrap clap2(clap);
    ClapTrap clap3(clap2);

    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(5);

    clap2.attack("target");
    clap2.takeDamage(5);
    clap2.beRepaired(5);

    return (0);
}