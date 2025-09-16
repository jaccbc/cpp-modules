/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:02:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/16 01:57:15 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

unsigned int ShrubberyCreationForm::getSignGrade() const { return sign; }

unsigned int ShrubberyCreationForm::getExecGrade() const { return exec; }

std::string const& ShrubberyCreationForm::getTarget() const { return target; }

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


const char* ShrubberyCreationForm::ShrubberyCreationFailureException::what() const throw() {
  return "The shrubbery form failed to create the file."; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
  : AForm("Shrubbery", sign, exec), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
  : AForm("Shrubbery", other.getSignGrade(), other.getExecGrade()), target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
  if (this != &other) target = other.getTarget();
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
