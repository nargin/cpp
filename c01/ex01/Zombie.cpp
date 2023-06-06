/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:49:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/06 22:37:24 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
	_name = name;
	_type = type;
}
Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << " " << this->_type << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) {
	return (this->_name);
}
