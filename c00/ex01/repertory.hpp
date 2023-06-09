/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:02:23 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/06 19:52:59 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPERTORY_HPP
# define REPERTORY_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void addContact(void);
	void searchContact(void);

private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int nbContacts;
};

#endif