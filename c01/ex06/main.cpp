/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:34:09 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/07 21:27:35 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static std::string toUpper(std::string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

int	main(int ac, char **av) {
	Harl	harl;

	if (ac != 2) {
		std::cout << "Usage: ./HarlFilter [level]" << std::endl;
		return (0);
	}
	std::string upped = toUpper(std::string(av[1]));
	harl.complain(upped);
	return (0);
}