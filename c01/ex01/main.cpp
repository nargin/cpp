/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:44:54 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/06 22:39:24 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	Zombie	*zombieHeap;
	Zombie	*zombieStack;

	zombieHeap = new Zombie("Heap", "Heap");
	zombieStack = newZombie("Stack", "Stack");
	zombieHeap->announce();
	zombieStack->announce();
	delete zombieHeap;
	delete zombieStack;
	randomChump("Random");
	return (0);
}