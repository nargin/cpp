/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:48:56 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/06 22:37:03 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(std::string name, std::string type);
		~Zombie(void);
		std::string	getName(void);
		void announce(void);
	private:
		std::string	_name;
		std::string	_type;
};

Zombie	*newZombie(std::string name, std::string type);
void	randomChump(std::string name);

#endif