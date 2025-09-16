/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:44:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/16 14:28:26 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::string const& AForm::getName() const { return name; }

bool AForm::getSignature() const { return signature; }

unsigned int AForm::getSignGrade() const { return sign; }

unsigned int AForm::getExecGrade() const { return exec; }

void AForm::beSigned(Bureaucrat const& bureau) {
  if (signature) throw AForm::FormAlreadySignedException();
  if (bureau.getGrade() > sign) throw AForm::GradeTooLowException();
  signature = true;
}

void AForm::execute(Bureaucrat const& executor) const {
  if (!signature) throw FormNotSignedException();
  if (executor.getGrade() > exec) throw GradeTooLowException();
  beExecuted();
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!"; }

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!"; }

const char* AForm::FormNotSignedException::what() const throw() {
  return "This form is not signed yet!"; }

const char* AForm::FormAlreadySignedException::what() const throw() {
  return "This form is already signed!"; }

AForm::AForm(const std::string name, const unsigned int sign, const unsigned int exec) 
  : name(name), sign(sign), exec(exec), signature(false) {
  if (sign > 150 || exec > 150) throw AForm::GradeTooLowException();
  if (sign < 1 || exec < 1) throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const& other) : name(other.name), 
    sign(other.sign), exec(other.exec), signature(other.signature) {}

AForm& AForm::operator=(AForm const& other) {
  if (this != &other) {
    signature = other.signature;
  }
  return *this;
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& out, AForm const& form) {
  return out << "** FORM **"
    << "\nNAME: " << form.getName()
    << "\nTARGET: " << form.getTarget()
    << "\nSIGNATURE: " << std::string(form.getSignature() ? "true" : "false")
    << "\nSIGN GRADE: " << form.getSignGrade()
    << "\nEXEC GRADE: " << form.getExecGrade() << "\n------------";
}
