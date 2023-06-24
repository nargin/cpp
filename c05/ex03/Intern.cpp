#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {};
Intern::Intern(Intern const &other) { *this = other; };
Intern::~Intern() {};

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return (*this);
}

Form *Intern::makeForm(std::string const &formName, std::string const &target) {
	Form *form = NULL;

	if (formName == "shrubbery creation")
		form = makeShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		form = makeRobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		form = makePresidentialPardonForm(target);
	else
		std::cout << "Intern can't create " << formName << " form" << std::endl;
	return (form);
}

Form *Intern::makeShrubberyCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
}