/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:32:07 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 20:52:37 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// returns a constant reference of the object string name
std::string const& Bureaucrat::getName() const { return name; }

// returns the Bureaucrat grade value
unsigned int Bureaucrat::getGrade() const { return grade; }

/*
  tries to sign the form and print it's name
  through an AForm object reference
  throws exception if it's not possible
*/
void Bureaucrat::signForm(AForm& form) {
  std::cout << name;
  try {
    form.beSigned(*this);
    std::cout << " signed " << form.getName() << " form.";
  }
  catch (std::exception &e) {
    std::cout << " couldn't sign " << form.getName();
    std::cout << " form because: " << e.what();
  }
  std::cout << std::endl;
}

/*
  tries to execute the from
  throw exception if it's not possible
*/
void Bureaucrat::executeForm(AForm const& form) const {
  try {
    form.execute(*this);
    std::cout << name << " executed ";
  }
  catch (std::exception &e) {
    std::cout << name << " couldn't execute ";
  }
  std::cout << form.getName() << " form." << std::endl;
}

/*
  virtualized functions from the std::exception object
*/
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade cannot be higher than 1!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade cannot be lower than 150!";
}

const char* Bureaucrat::InvalidGradeException::what() const throw() {
  return "Bureaucrat grade is invalid (out of bounds range)!";
}

// default object constructor
Bureaucrat::Bureaucrat() : name("Marvin"), grade(42) {}

/*
  parameterized object constructor
  throws an exception if grade is out of bounds
*/
Bureaucrat::Bureaucrat(std::string const& name, const unsigned int n)
  : name(name), grade(n) {
  if (grade > 150) throw Bureaucrat::GradeTooLowException();
  else if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

/*
  copy object constructor
  initializes an object with 'other' object values
  throws an exception if the grade is out of bounds
*/
Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade) {
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    else if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

// overload of assignment operator ( = )
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
  if (this != &other) grade = other.grade;
  return *this;
}

/*
  object grade value manipulation w/
  overload pre/post and de/increment operators
  if the grade is not possible to change (out of bounds) throws an exception
*/

// pre increment ++i
Bureaucrat& Bureaucrat::operator++() {
  if (grade <= 1) throw Bureaucrat::GradeTooHighException();
  grade -= 1;
  return *this;
}

// post increment i++
Bureaucrat Bureaucrat::operator++(int) {
  if (grade <= 1) throw Bureaucrat::GradeTooHighException();
  Bureaucrat result(name, grade--);
  return result;
}

// pre decrement --i
Bureaucrat& Bureaucrat::operator--() {
  if (grade >= 150) throw Bureaucrat::GradeTooLowException();
  grade += 1;
  return *this;
}

// post decrement i--
Bureaucrat Bureaucrat::operator--(int) {
  if (grade >= 150) throw Bureaucrat::GradeTooLowException();
  Bureaucrat result(name, grade++);
  return result;
}

// object ~destructor
Bureaucrat::~Bureaucrat() {}

/*
  overload of insertion operator ( << )
  returns a reference of the std::ostream object
  with all the Bureaucrat values printed
*/
std::ostream& operator<<(std::ostream& out, Bureaucrat const& b) {
  return out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
