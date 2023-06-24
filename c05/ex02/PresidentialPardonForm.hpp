#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(void);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const & rhs);

		std::string const	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form & form) const;
		void				executeForm(Form const & form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};