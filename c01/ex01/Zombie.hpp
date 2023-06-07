/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:48:56 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 01:38:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie(void);
		std::string	getName(std::string name);
		void announce(void);
	private:
		std::string	_name;
};

Zombie	*newZombie(std::string name, std::string type);
Zombie  *ZombieHorde(int N, std::string type);

#endif