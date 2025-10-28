/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:44:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 10:22:38 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// retuns a constant reference of the string name
std::string const& Form::getName() const { return name; }

// returns the bool value of the object signaure variable
bool Form::getSign() const { return signature; }

// returns the number of the grade to sign
unsigned int Form::getSignGrade() const { return sign; }

//returns the number of the grade to execute
unsigned int Form::getExecGrade() const { return exec; }

/*
  verifies if the Bureuacrat's and Form's grade is within valid ranges
  and if the Form's grade is too high to be signed by the Bureaucrat
  throws an exception if any of these conditions are met
  otherwise signs the Form
*/
void Form::beSigned(Bureaucrat const& bureau) {
  if (sign > MIN_GRADE || exec > MIN_GRADE)
    throw Form::GradeTooLowException();
  else if (sign < MAX_GRADE || exec < MAX_GRADE)
    throw Form::GradeTooHighException();
  if (bureau.getGrade() < MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (bureau.getGrade() > MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  if (bureau.getGrade() > sign)
    throw Form::GradeTooHighException();
  signature = true;
}

/*
  virtualized functions from the std::exception object
*/
const char* Form::GradeTooHighException::what() const throw() {
  return "Form grade is too high!"; }

const char* Form::GradeTooLowException::what() const throw() {
  return "Form grade is too low"; }

// default object constructor
Form::Form() : name("Exam"), sign(42), exec(24), signature(false) {}

/* 
  parameterized object constructor
  throws an exception if any grade is out of bounds
*/
Form::Form(const std::string name, const unsigned int sign, const unsigned int exec) 
  : name(name), sign(sign), exec(exec), signature(false) {
  if (sign > MIN_GRADE || exec > MIN_GRADE) throw Form::GradeTooLowException();
  if (sign < MAX_GRADE || exec < MAX_GRADE) throw Form::GradeTooHighException();
}

/*
  copy object constructor
  initializes an object with 'other' object values
  throws an exception if the grade is out of bounds
*/
Form::Form(Form const& other) : name(other.name), 
    sign(other.sign), exec(other.exec), signature(false) {
  if (sign > MIN_GRADE || exec > MIN_GRADE) throw Form::GradeTooLowException();
  if (sign < MAX_GRADE || exec < MAX_GRADE) throw Form::GradeTooHighException();
}

// overload of assignment operator ( = )
Form& Form::operator=(const Form& other) {
  if (this != &other) {
    signature = other.signature;
  }
  return *this;
}

// object ~destructor
Form::~Form() {}

/*
  overload of insertion operator ( << )
  returns a reference of the std::ostream object
  with all the Form values printed
*/
std::ostream& operator<<(std::ostream& out, Form const& form) {
  std::string signature(form.getSign() ? "true" : "false");
  return out << "** FORM CONTENT **\nNAME: " << form.getName()
    << "\nSIGNATURE: " << signature << "\nSIGN GRADE: " << form.getSignGrade()
    << "\nEXEC GRADE: " << form.getExecGrade() << "\n******************";
}
