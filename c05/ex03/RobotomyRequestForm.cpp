#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default"){};
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target){};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy), _target(copy._target){};

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return (*this);
	Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}