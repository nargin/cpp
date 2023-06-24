/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:29:59 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 20:23:10 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int const gradeToSign, int const gradeToExec):
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src):
	_name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
}

Form::~Form(void){}

Form &	Form::operator=(Form const & rhs) {
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

std::string const	Form::getName(void) const { return (this->_name); }

bool	Form::getSigned(void) const { return (this->_signed); }

int	Form::getGradeToSign(void) const { return (this->_gradeToSign); }

int	Form::getGradeToExec(void) const { return (this->_gradeToExec); }

void		Form::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char *		Form::GradeTooHighException::what(void) const throw() { return ("Grade too high"); }
const char *		Form::GradeTooLowException::what(void) const throw() { return ("Grade too low"); }
const char *		Form::FormNotSignedException::what(void) const throw() { return ("Form not signed"); }

std::ostream &	operator<<(std::ostream & o, Form const & rhs){
	if (rhs.getSigned())
		o << rhs.getName() << " is signed and requires a grade " << rhs.getGradeToSign() << " to be signed and a grade " << rhs.getGradeToExec() << " to be executed" << std::endl;
	else
		o << rhs.getName() << " is not signed and requires a grade " << rhs.getGradeToSign() << " to be signed and a grade " << rhs.getGradeToExec() << " to be executed" << std::endl;
	return (o);
};