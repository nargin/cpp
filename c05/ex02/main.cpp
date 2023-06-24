/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:29:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 20:20:15 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Bureaucrat		*hermes = new Bureaucrat("Hermes Conrad", 37);
	Bureaucrat		*leela = new Bureaucrat("Turanga Leela", 1);
	Bureaucrat		*bender = new Bureaucrat("Bender Bending Rodriguez", 150);
	Form			*shrubbery = new ShrubberyCreationForm("home");
	Form			*robotomy = new RobotomyRequestForm("Bender");
	Form			*presidential = new PresidentialPardonForm("Zapp Brannigan");

	std::cout << *hermes << *leela << *bender << std::endl;
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	hermes->signForm(*shrubbery);
	hermes->signForm(*robotomy);
	hermes->signForm(*presidential);
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	leela->signForm(*shrubbery);
	leela->signForm(*robotomy);
	leela->signForm(*presidential);
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	bender->signForm(*shrubbery);
	bender->signForm(*robotomy);
	bender->signForm(*presidential);
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	hermes->executeForm(*shrubbery);
	hermes->executeForm(*robotomy);
	hermes->executeForm(*presidential);
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	leela->executeForm(*shrubbery);
	leela->executeForm(*robotomy);
	leela->executeForm(*presidential);
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	bender->executeForm(*shrubbery);
	bender->executeForm(*robotomy);
	bender->executeForm(*presidential);
	std::cout << *shrubbery << *robotomy << *presidential << std::endl;

	delete hermes;
	delete leela;
	delete bender;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	return (0);
}