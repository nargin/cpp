/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:07:39 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/23 19:59:26 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# define SIGN_GRADE_SHRU 145
# define EXEC_GRADE_SHRU 137

#define TREE "                                                        .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;.\n\
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,"

# include "Form.hpp"

class ShrubberyCreationForm: public Form {
	public:
	ShrubberyCreationForm() : Form("ShrubberyCreationForm", SIGN_GRADE_SHRU, EXEC_GRADE_SHRU){};
	ShrubberyCreationForm(std::string const &name) : Form(name, SIGN_GRADE_SHRU, EXEC_GRADE_SHRU){};
	~ShrubberyCreationForm(){};
	ShrubberyCreationForm(const ShrubberyCreationForm &src){ *this = src; };
	
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src){
		if (this != &src)
			this->Form::operator=(src);
		return *this;
	};
	int execute(Bureaucrat const &executor) const{
		if (!this->getSign())
			throw Form::FormNotSignedException();
		if (executor.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException();
		std::string filename = this->getName() + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (file.is_open()){
			file << TREE;
			file.close();
		}
		else
			std::cout << "Error: Unable to open file" << std::endl;
		return 0;
	};

private:
	std::string const name;
	bool sign;
};

#endif