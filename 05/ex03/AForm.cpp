/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:44:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 11:42:31 by joandre-         ###   ########.fr       */
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
  verifies if the form is already signed
  checks both objects grade boundaries
  and if the Bureaucrat has enough grade to sign the form
  throws an exception if any grade is out of bound
  otherwise signs the form
*/
void AForm::beSigned(Bureaucrat const& bureau) {
  if (signature) throw AForm::FormAlreadySignedException();
  if (sign > MIN_GRADE)
    throw AForm::GradeTooLowException();
  else if (sign < MAX_GRADE)
    throw AForm::GradeTooHighException();
  if (bureau.getGrade() < MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (bureau.getGrade() > MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  if (bureau.getGrade() > sign)
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
  if (executor.getGrade() < MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (executor.getGrade() > MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  if (executor.getGrade() > exec)
    throw AForm::GradeTooHighException();
  beExecuted();
}

/*
  virtualized function from the std::exception object
*/
const char* AForm::GradeTooHighException::what() const throw() {
  return "Base form grade is too high!"; }

const char* AForm::GradeTooLowException::what() const throw() {
  return "Base form grade is too low!"; }

const char* AForm::FormNotSignedException::what() const throw() {
  return "Base form is not signed yet!"; }

const char* AForm::FormAlreadySignedException::what() const throw() {
  return "Base form is already signed!"; }

// default object constructor
AForm::AForm() : name("Exam"), sign(42), exec(24), signature(false) {}

/*
  parameterized object constructor
  throws an exception if any grade is out of bounds
*/
AForm::AForm(const std::string name, const unsigned int sign, const unsigned int exec) 
  : name(name), sign(sign), exec(exec), signature(false) {
  if (sign > MIN_GRADE || exec > MIN_GRADE) throw AForm::GradeTooLowException();
  if (sign < MAX_GRADE || exec < MAX_GRADE) throw AForm::GradeTooHighException();
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
  return out << "** BASE FORM CONTENT **"
    << "\nNAME: " << form.getName()
    << "\nTARGET: " << form.getTarget()
    << "\nSIGNATURE: " << std::string(form.getSign() ? "true" : "false")
    << "\nSIGN GRADE: " << form.getSignGrade()
    << "\nEXEC GRADE: " << form.getExecGrade() << "\n***********************";
}
