/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:29:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/19 15:30:43 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	*romain = new Bureaucrat("Romain", 1);
	Bureaucrat	*romain2 = new Bureaucrat("Romain2", 150);

	std::cout << *romain << std::endl;
	std::cout << *romain2 << std::endl;

	try {
		romain->incrementGrade();
		std::cout << *romain << std::endl;
		romain->incrementGrade();
		std::cout << *romain << std::endl;
		romain->incrementGrade();
		std::cout << *romain << std::endl;
		romain->incrementGrade();
		std::cout << *romain << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	try	{
		romain2->decrementGrade();
		std::cout << *romain2 << std::endl;
		romain2->decrementGrade();
		std::cout << *romain2 << std::endl;
		romain2->decrementGrade();
		std::cout << *romain2 << std::endl;
		romain2->decrementGrade();
		std::cout << *romain2 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}