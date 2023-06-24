/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:30:03 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 20:22:34 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Bureaucrat;
class Form
{

	public:
		Form(void);
		Form(std::string const name, int const gradeToSign, int const gradeToExec);
		Form(Form const & src);
		virtual ~Form(void);

		Form &	operator=(Form const & rhs);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int				getGradeToSign(void) const;
		int 			getGradeToExec(void) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;

		void				beSigned(Bureaucrat const & bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *		what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *		what(void) const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *		what(void) const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);