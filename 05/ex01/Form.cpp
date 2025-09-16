/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:44:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/15 19:23:08 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string const& Form::getName() const { return name; }

bool Form::getSign() const { return signature; }

unsigned int Form::getGrade(bool g) const {
  if (g) return exec;
  else return sign;
}

void Form::beSigned(Bureaucrat const& bureau) {
  if (bureau.getGrade() > sign || bureau.getGrade() > exec)
    throw Form::GradeTooLowException();
  if (sign < 1 || exec < 1) throw Form::GradeTooHighException();
  signature = true;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Form grade is too high!"; }

const char* Form::GradeTooLowException::what() const throw() {
  return "Form grade is too low!"; }

Form::Form(const std::string name, const unsigned int sign, const unsigned int exec) 
  : name(name), sign(sign), exec(exec), signature(false) {
  if (sign > 150 || exec > 150) throw Form::GradeTooLowException();
  if (sign < 1 || exec < 1) throw Form::GradeTooHighException();
}

Form::Form(Form const& other) : name(other.name), 
    sign(other.sign), exec(other.exec), signature(other.signature) {}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    signature = other.signature;
  }
  return *this;
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& out, Form const& form) {
  std::string sign(form.getSign() ? "true" : "false");
  return out << "** FORM **\nNAME: " << form.getName()
    << "\nSIGNATURE: " << sign << "\nSIGN GRADE: " << form.getGrade(0)
    << "\nEXEC GRADE: " << form.getGrade(1) << "\n------------";
}
