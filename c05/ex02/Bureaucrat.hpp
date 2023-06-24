/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:18:51 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/24 20:21:30 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define MAX_GRADE 1
# define MIN_GRADE 150

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;
class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		Bureaucrat&	operator=(Bureaucrat const & rhs);
		
		std::string const	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form & form) const;
		void 				executeForm(Form const &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*		what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*		what(void) const throw();
		};

	private:
		Bureaucrat(void);

		std::string const	_name;
		int					_grade;

};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & rhs);