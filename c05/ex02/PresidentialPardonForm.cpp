#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default"){};
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target){};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), _target(copy._target){};
PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this == &copy)
		return (*this);
	Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
	o << rhs.getName() << " is ";
	if (rhs.getSigned() == false)
		o << "not ";
	o << "signed, grade to sign is " << rhs.getGradeToSign() << ", grade to execute is " << rhs.getGradeToExec() << "." << std::endl;
	return (o);
}