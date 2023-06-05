/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:02:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/05/09 16:43:23 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPERTORY_HPP
# define REPERTORY_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	bool addContact(Contact contact);
	void displayContacts() const;
	void searchContact(std::string keyword) const;

private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int nbContacts;
};

#endif