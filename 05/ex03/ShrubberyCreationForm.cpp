/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:02:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 17:27:31 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// returns the number of the grade to sign
unsigned int ShrubberyCreationForm::getSignGrade() const { return sign; }

// returns the number of the grade to execute
unsigned int ShrubberyCreationForm::getExecGrade() const { return exec; }

// returns a constant string reference of the target variable
std::string const& ShrubberyCreationForm::getTarget() const { return target; }

/*
  uses a std::ofstream object to join the object target string
  to the _shrubbery suffix
  throws an exception if the file cannot be created
*/
void ShrubberyCreationForm::beExecuted() const {
  std::ofstream ofs;
  ofs.open((target + "_shrubbery").c_str());
  if (!ofs.is_open()) throw ShrubberyCreationFailureException();
  ofs << "            ,@@@@@@@," << std::endl
      << "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
      << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
      << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
      << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
      << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
      << "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
      << "    |o|        | |         | |" << std::endl
      << "    |.|        | |         | |" << std::endl
      << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
  ofs.close();
}

// virtualized function from the std::exception object
const char* ShrubberyCreationForm::ShrubberyCreationFailureException::what() const throw() {
  return "The shrubbery form failed to create the file."; }

// defeault object contructor
ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("Shrubbery", sign, exec), target("ShrubberyCreationForm") {}

// parameterized object constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
  : AForm("Shrubbery", sign, exec), target(target) {}

/*
  copy object constructor
  initializes an object with 'other' object values
*/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
  : AForm("Shrubbery", other.getSignGrade(), other.getExecGrade()), target(other.getTarget()) {}

// overload of assignment operator ( = )
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
  if (this != &other) target = other.getTarget();
  return *this;
}

// object ~destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}
