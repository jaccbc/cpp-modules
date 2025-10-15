/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:44:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 20:58:16 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// retuns a constant reference of the object name value
std::string const& AForm::getName() const { return name; }

// returns the bool value of the object signaure variable
bool AForm::getSign() const { return signature; }

// returns the number of the grade to sign
unsigned int AForm::getSignGrade() const { return sign; }

//returns the number of the grade to execute
unsigned int AForm::getExecGrade() const { return exec; }

/*
  first verifies if the form is already signed
  checks both objects grade boundaries
  and if the Bureaucrat has enough grade to sign the form
  throws an exception if any grade is out of bound
  otherwise signs the form
*/
void AForm::beSigned(Bureaucrat const& bureau) {
  if (signature) throw AForm::FormAlreadySignedException();
  if (sign > 150 || exec > 150 || sign < 1 || exec < 1)
    throw AForm::InvalidGradeException();
  else if (bureau.getGrade() < 1 || bureau.getGrade() > 150)
    throw Bureaucrat::InvalidGradeException();
  if (bureau.getGrade() > sign || bureau.getGrade() > exec)
    throw AForm::GradeTooHighException();
  signature = true;
}

/*
  verifies if the form is signed
  and if Bureaucrat's grade is within valid ranges
  throws an exception when any of these conditions are met
  otherwise proceeds to execute the form
*/
void AForm::execute(Bureaucrat const& executor) const {
  if (!signature) throw AForm::FormNotSignedException();
  if (executor.getGrade() < 1 || executor.getGrade() > 150)
    throw Bureaucrat::InvalidGradeException();
  if (executor.getGrade() > sign || executor.getGrade() > exec)
    throw AForm::GradeTooHighException();
  beExecuted();
}

/*
  virtualized function from the std::exception object
*/
const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!"; }

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!"; }

const char* AForm::InvalidGradeException::what() const throw() {
  return "Grade is invalid (out of bounds)!"; }

const char* AForm::FormNotSignedException::what() const throw() {
  return "This form is not signed yet!"; }

const char* AForm::FormAlreadySignedException::what() const throw() {
  return "This form is already signed!"; }

// default object constructor
AForm::AForm() : name("AExam"), sign(42), exec(42), signature(false) {}

/*
  parameterized object constructor
  throws an exception if any grade is out of bounds
*/
AForm::AForm(const std::string name, const unsigned int sign, const unsigned int exec) 
  : name(name), sign(sign), exec(exec), signature(false) {
  if (sign > 150 || exec > 150) throw AForm::GradeTooLowException();
  if (sign < 1 || exec < 1) throw AForm::GradeTooHighException();
}

/*
  copy object constructor
  initializes an object with 'other' object values
  throws an exception if the grade is out of bounds
*/
AForm::AForm(AForm const& other) : name(other.name), 
    sign(other.sign), exec(other.exec), signature(false) {}

// overload of assignment operator ( = )
AForm& AForm::operator=(AForm const& other) {
  if (this != &other) signature = other.signature;
  return *this;
}

// object ~destructor
AForm::~AForm() {}

/*
  overload of insertion operator ( << )
  returns a reference of the std::ostream object
  with all the AForm values printed
*/
std::ostream& operator<<(std::ostream& out, AForm const& form) {
  return out << "** AFORM **"
    << "\nNAME: " << form.getName()
    << "\nTARGET: " << form.getTarget()
    << "\nSIGNATURE: " << std::string(form.getSign() ? "true" : "false")
    << "\nSIGN GRADE: " << form.getSignGrade()
    << "\nEXEC GRADE: " << form.getExecGrade() << "\n------------";
}
