/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:30:03 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/23 19:17:40 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string const name, int const gradeToSign, int const gradeToExec)  : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
			if (gradeToSign < 1 || gradeToExec < 1)
				throw Form::GradeTooHighException();
			else if (gradeToSign > 150 || gradeToExec > 150)
				throw Form::GradeTooLowException();
		};
		Form(Form const & src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()){ *this = src; };
		virtual ~Form(void){};

		Form &	operator=(Form const & rhs){
			if (this != &rhs)
				*this = rhs;
			return (*this);
		};

		std::string const	getName(void) const{ return (this->_name); };
		bool				getSigned(void) const{ return (this->_signed); };
		int				getGradeToSign(void) const{ return (this->_gradeToSign); };
		int 			getGradeToExec(void) const{	return (this->_gradeToExec); };

		void				beSigned(Bureaucrat const & bureaucrat){
			if (bureaucrat.getGrade() > this->_gradeToSign)
				throw Form::GradeTooLowException();
			else
				this->_signed = true;
		};

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void){};
				GradeTooHighException(GradeTooHighException const & src){ *this = src; };
				virtual ~GradeTooHighException(void) throw(){};

				GradeTooHighException &	operator=(GradeTooHighException const & rhs){ (void)rhs; return (*this); };
				virtual const char *		what(void) const throw(){ return ("Grade too high"); };
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void){};
				GradeTooLowException(GradeTooLowException const & src){	*this = src; };
				virtual ~GradeTooLowException(void) throw(){};

				GradeTooLowException &	operator=(GradeTooLowException const & rhs){ (void)rhs;	return (*this); };
				virtual const char *		what(void) const throw(){ return ("Grade too low"); };
		};

	private:
		Form(void) : _name("default"), _signed(false), _gradeToSign(1), _gradeToExec(1){};

		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs){
	if (rhs.getSigned())
		o << rhs.getName() << " is signed and requires a grade " << rhs.getGradeToSign() << " to be signed and a grade " << rhs.getGradeToExec() << " to be executed" << std::endl;
	else
		o << rhs.getName() << " is not signed and requires a grade " << rhs.getGradeToSign() << " to be signed and a grade " << rhs.getGradeToExec() << " to be executed" << std::endl;
	return (o);
};

#endif