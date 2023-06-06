/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:35:07 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/06 22:23:25 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

std::string	allupper(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

PhoneBook::PhoneBook() : contacts(), nbContacts(0) {
	;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void PhoneBook::addContact() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter the first name: ";
	std::getline(std::cin, firstName);
	if (firstName.empty()) {
		std::cout << "First name cannot be empty." << std::endl;
		return ;
	}
	std::cout << "Enter the last name: ";
	std::getline(std::cin, lastName);
	if (lastName.empty()) {
		std::cout << "Last name cannot be empty." << std::endl;
		return ;
	}
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty()) {
		std::cout << "Nickname cannot be empty." << std::endl;
		return ;
	}
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty()) {
		std::cout << "Phone number cannot be empty." << std::endl;
		return ;
	}
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty()) {
		std::cout << "Darkest secret cannot be empty." << std::endl;
		return ;
	}
	this->contacts[this->nbContacts].setFirstName(firstName);
	this->contacts[this->nbContacts].setLastName(lastName);
	this->contacts[this->nbContacts].setNickname(nickname);
	this->contacts[this->nbContacts].setPhoneNumber(phoneNumber);
	this->contacts[this->nbContacts].setDarkestSecret(darkestSecret);
	this->nbContacts++;
	if (this->nbContacts == MAX_CONTACTS)
		this->nbContacts = 0;
}

static void	printContact(std::string str) {
	if (str.length() > 10)
		std::cout << " " << str.substr(0, 9) << ". |";
	else
		std::cout << " " << str << " |";
}

void PhoneBook::searchContact(void) {
	if (this->nbContacts == 0 && this->contacts[0].getFirstName().empty()) {
		std::cout << "No contact to display." << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_CONTACTS; i++){
		if (this->contacts[i].getFirstName().empty())
			continue ;
		std::cout << i + 1 << " |";
		printContact(this->contacts[i].getFirstName());
		printContact(this->contacts[i].getLastName());
		printContact(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "Enter the index of the contact you want to see: ";
	std::string	index;
	std::getline(std::cin, index);
	if (index.empty()) {
		std::cout << "Index cannot be empty." << std::endl;
		return ;
	}
	if (index.length() > 1 || index[0] < '1' || index[0] > '8') {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	int	i = index[0] - '0';
	if (i > this->nbContacts) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First name: " << this->contacts[i - 1].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[i - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[i - 1].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[i - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[i - 1].getDarkestSecret() << std::endl;
}

int	main(void)
{
	PhoneBook	repertory;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (allupper(command) == "ADD")
			repertory.addContact();
		else if (allupper(command) == "SEARCH")
			repertory.searchContact();
		else if (allupper(command) == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}