/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:52:53 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/23 19:35:39 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define SIGN_GRADE 72
# define EXEC_GRADE 45

# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form {

public:
	RobotomyRequestForm() : Form("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE, "default"){};
	RobotomyRequestForm(std::string const &name) : Form("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE, name){};
	~RobotomyRequestForm(){};
	RobotomyRequestForm(const RobotomyRequestForm &src){ *this = src; };
	
	RobotomyRequestForm& operator=(const RobotomyRequestForm &src){
		if (this != &src)
			this->Form::operator=(src);
		return *this;
	};
	int execute(Bureaucrat const &executor) const{
		if (executor.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException();
		std::cout << "Drill sound..." << std::endl;
		if (rand() % 2)
			std::cout << this->getName() << " has been robotomized successfully." << std::endl;
		else
			std::cout << this->getName() << " has not been robotomized successfully." << std::endl;
		return 0;
	};

private:
	std::string const name;
	bool sign;
};

#endif