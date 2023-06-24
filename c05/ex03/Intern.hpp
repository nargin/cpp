#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();

		Intern &operator=(Intern const &other);

		Form *makeForm(std::string const &formName, std::string const &target);

	private:
		Form *makeShrubberyCreationForm(std::string const &target);
		Form *makeRobotomyRequestForm(std::string const &target);
		Form *makePresidentialPardonForm(std::string const &target);
};