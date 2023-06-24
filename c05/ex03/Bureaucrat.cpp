/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:18:41 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 20:21:45 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name){
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
};
Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()){ *this = src; };
Bureaucrat::Bureaucrat(void) : _name("Default"){ this->_grade = 150; };
Bureaucrat::~Bureaucrat(void){};

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs){
	this->_grade = rhs.getGrade();
	return (*this);
};

std::string const	Bureaucrat::getName(void) const{ return (this->_name); };
int					Bureaucrat::getGrade(void) const{ return (this->_grade); };
void				Bureaucrat::incrementGrade(void){
	this->_grade - 1 < MIN_GRADE ? throw Bureaucrat::GradeTooHighException() : this->_grade--; };
void				Bureaucrat::decrementGrade(void){
	this->_grade + 1 > MAX_GRADE ? throw Bureaucrat::GradeTooLowException() : this->_grade++; };

void				Bureaucrat::signForm(Form & form) const{
	try{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	} catch (std::exception & e){
		std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
};
void 				Bureaucrat::executeForm(Form const &form){
	try{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	} catch (std::exception & e){
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
};

const char*				Bureaucrat::GradeTooHighException::what(void) const throw(){ return ("Grade too high"); };
const char*				Bureaucrat::GradeTooLowException::what(void) const throw(){ return ("Grade too low"); };


std::ostream& operator<<(std::ostream& o, Bureaucrat const & rhs){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
};