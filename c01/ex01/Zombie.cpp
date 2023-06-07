/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:49:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 01:37:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	;
}
Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(std::string name) {
	return (this->_name = name);
}
