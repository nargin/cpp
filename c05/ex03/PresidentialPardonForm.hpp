#pragma once

#include "Form.hpp"
#include <string>
#include <iostream>

class Form;

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		void execute(Bureaucrat const &executor) const;
};