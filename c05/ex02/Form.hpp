/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:30:03 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 16:32:31 by romaurel         ###   ########.fr       */
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
		Form(std::string const name, int const gradeToSign, int const gradeToExec);
		Form(Form const & src);
		~Form(void);

		Form &	operator=(Form const & rhs);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int				getGradeToSign(void) const;
		int 			getGradeToExec(void) const;

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

	private:
		Form(void);

		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);