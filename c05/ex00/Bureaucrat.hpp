/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:18:51 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/19 17:29:53 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, int grade) : _name(name){
			if (grade < MAX_GRADE)
				throw Bureaucrat::GradeTooHighException();
			else if (grade > MIN_GRADE)
				throw Bureaucrat::GradeTooLowException();
			else
				this->_grade = grade;
		};
		Bureaucrat(Bureaucrat const & src){
			*this = src;
		};
		~Bureaucrat(void){
		};

		Bureaucrat&	operator=(Bureaucrat const & rhs){
			if (this != &rhs)
				this->_grade = rhs._grade;
			return *this;
		};

		std::string const	getName(void) const{
			return this->_name;
		};
		int					getGrade(void) const{
			return this->_grade;
		};

		void				incrementGrade(void){
			if (this->_grade - 1 < MAX_GRADE)
				throw Bureaucrat::GradeTooHighException();
			else
				this->_grade--;
		};
		void				decrementGrade(void){
			if (this->_grade + 1 > MIN_GRADE)
				throw Bureaucrat::GradeTooLowException();
			else
				this->_grade++;
		};

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void){};
				GradeTooHighException(GradeTooHighException const & src){
					*this = src;
				};
				~GradeTooHighException(void) throw(){};

				GradeTooHighException&	operator=(GradeTooHighException const & rhs){
					(void)rhs;
					return *this;
				};

				virtual const char*		what(void) const throw(){
					return "Grade too high";
				};
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void){};
				GradeTooLowException(GradeTooLowException const & src){
					*this = src;
				};
				~GradeTooLowException(void) throw(){};

				GradeTooLowException&	operator=(GradeTooLowException const & rhs){
					(void)rhs;
					return *this;
				};

				virtual const char*		what(void) const throw(){
					return "Grade too low";
				};
		};

	private:
		Bureaucrat(void){
			this->_grade = 0;
		};

		std::string const	_name;
		int					_grade;

	std::ostream&	operator<<(std::ostream& o, Bureaucrat const & rhs){
		o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
		return o;
	};
};

#endif