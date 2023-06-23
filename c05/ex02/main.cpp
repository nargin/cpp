/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:29:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/23 19:16:09 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void) {
	Bureaucrat	*romain = new Bureaucrat("Romain", 1);
	Bureaucrat	*jean = new Bureaucrat("Jean", 150);
	Form		*shrubbery = new ShrubberyCreationForm("Shrubbery");
	Form		*robotomy = new RobotomyRequestForm("Robotomy");
	Form		*presidential = new PresidentialPardonForm("Presidential");

	std::cout << *romain << std::endl;
	std::cout << *jean << std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;

	std::cout << std::endl << "Test signForm" << std::endl;
	romain->signForm(*shrubbery);
	romain->signForm(*robotomy);
	romain->signForm(*presidential);
	jean->signForm(*shrubbery);
	jean->signForm(*robotomy);
	jean->signForm(*presidential);

	std::cout << std::endl << "Test executeForm" << std::endl;
	romain->executeForm(*shrubbery);
	romain->executeForm(*robotomy);
	romain->executeForm(*presidential);
	jean->executeForm(*shrubbery);
	jean->executeForm(*robotomy);
	jean->executeForm(*presidential);

	delete romain;
	delete jean;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	return 0;
}
