#pragma once

#include "Form.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Form;

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		void execute(Bureaucrat const &executor) const;
};