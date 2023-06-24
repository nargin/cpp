/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:29:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 15:58:57 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	*romain = new Bureaucrat("Romain", 1);
	Bureaucrat	*romain2 = new Bureaucrat("Romain2", 150);
	Form		*form = new Form("Form", 1, 1);
	Form		*form2 = new Form("Form2", 150, 150);

	std::cout << *romain << std::endl;
	std::cout << *romain2 << std::endl;
	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;

	try	{ romain->incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		romain2->decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		form->beSigned(*romain);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		form2->beSigned(*romain2);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *romain << std::endl;
	std::cout << *romain2 << std::endl;
	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;
	delete romain;
	delete romain2;
	delete form;
	delete form2;
	return (0);
}