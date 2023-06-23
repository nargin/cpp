/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:47:35 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/23 19:36:13 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# define SIGN_GRADE 25
# define EXEC_GRADE 5

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string const target): Form(target, SIGN_GRADE, EXEC_GRADE){};
		PresidentialPardonForm(PresidentialPardonForm const & src){ *this = src;};
		~PresidentialPardonForm(void){};

		PresidentialPardonForm&	operator=(PresidentialPardonForm const & rhs){
			if (this != &rhs)
				this->Form::operator=(rhs);
			return *this;
		};

		void	execute(Bureaucrat const & executor) const{
			if (this->getSigned() == false)
				throw Form::FormNotSignedException();
			else if (executor.getGrade() > this->getExecGrade())
				throw Form::GradeTooLowException();
			else
				std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
		};
	private:
		PresidentialPardonForm(void) : Form("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE){};
};

#endif