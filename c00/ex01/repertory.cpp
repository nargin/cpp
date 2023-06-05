/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:50:41 by romaurel          #+#    #+#             */
/*   Updated: 2023/05/09 16:48:37 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

std::string	allupper(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

std::string	getInput(std::string prompt)
{
	std::string	input;

	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	return (input);
}

PhoneBook::PhoneBook(void)
{
	this->nbContacts = 0;
}

int	main(void)
{
	PhoneBook	repertory;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		// if (command == "ADD")
			// repertory.addContact();
		// else if (command == "SEARCH")
			// repertory.searchContact();
		if (allupper(command) == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}