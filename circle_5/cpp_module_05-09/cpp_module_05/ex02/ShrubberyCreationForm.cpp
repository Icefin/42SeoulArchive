/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:46 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 16:30:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.h"

const char* ShrubberyCreationForm::FileIOException::what() const throw()
{
	return "FileStreamFail";
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "None", ShrubberyCreationForm::s_SignGrade, ShrubberyCreationForm::s_ExecuteGrade)
{
	//__noop;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", target, ShrubberyCreationForm::s_SignGrade, ShrubberyCreationForm::s_ExecuteGrade)
{
	//__noop;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& op)
	: AForm(op)
{
	//__noop;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//__noop;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& op)
{
	AForm::operator=(op);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkExecutable(executor);
	static std::string asciiTree = "\n \
                                              .\n \
                                   .         ;\n \
      .              .              ;%     ;;\n \
        ,           ,                :;%  %;\n \
         :         ;                   :;%;\'     .,\n \
,.        %;     %;            ;        %;\'    ,;\n \
  ;       ;%;  %%;        ,     %;    ;%;    ,%\'\n \
   %;       %;%;      ,  ;       %;  ;%;   ,%;\'\n \
    ;%;      %;        ;%;        % ;%;  ,%;\'\n \
     `%;.     ;%;     %;\'         `;%%;.%;\'\n \
      `:;%.    ;%%. %@;        %; ;@%;%\'\n \
         `:%;.  :;bd%;          %;@%;\'\n \
           `@%:.  :;%.         ;@@%;\'\n \
             `@%.  `;@%.      ;@@%;\n \
               `@%%. `@%%    ;@@%;\n \
                 ;@%. :@%%  %@@%;\n \
                   %@bd%%%bd%%:;\n \
                     #@%%%%%:;;\n \
                     %@@%%%::;\n \
                     %@@@%(o);  . \'\n \
                     %@@@o%;:(.,\'\n \
                 `.. %@@@o%::;\n \
                    `)@@@o%::;\n \
                     %@@(o)::;\n \
                    .%@@@@%::;\n \
                    ;%@@@@%::;.\n \
                   ;%@@@@%%:;;;.\n \
               ...;%@@@@@%%:;;;;,..  \n";

	std::ofstream out;
	out.open(this->getTarget() + "_shrubbery");
	if (out.is_open() == false)
		throw(FileIOException());
	out << asciiTree;
	out.close();
}