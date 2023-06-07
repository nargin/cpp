/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:27:25 by codespace         #+#    #+#             */
/*   Updated: 2023/06/07 01:39:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string type)
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombies[i].getName(type);
    return (zombies);
}