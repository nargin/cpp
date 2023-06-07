/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:44:54 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 01:37:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	Zombie *muchos = ZombieHorde(10, "broZoi");
	for (int i = 0; i < 10; i++)
		muchos[i].announce();
	delete[] muchos;
	return 0;
}