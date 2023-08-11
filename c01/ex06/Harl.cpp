/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:33:04 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 21:30:23 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	switch (i) {
		case 0:
			std::cout << "[DEBUG]\nA lot of bugs go fix" << std::endl;
		case 1:
			std::cout << "[INFO]\nNo info go away" << std::endl;
		case 2:
			std::cout << "[WARNING]\nThis is a warning!" << std::endl;
		case 3:
			std::cout << "[ERROR]\nErrors errors errors" << std::endl;
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
	}
	return ;
}
