/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:29:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/25 01:15:27 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void){
	Intern		intern;
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	jim("Jim", 150);
	Form		*form;

	form = intern.makeForm("shrubbery creation", "home");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("robotomy request", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	jim.executeForm(*form);
	delete form;
	return (0);
}