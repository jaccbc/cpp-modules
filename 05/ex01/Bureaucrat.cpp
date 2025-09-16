/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:32:07 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/15 19:16:40 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::string const& Bureaucrat::getName() const { return name; }

unsigned int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::signForm(Form& form) {
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade cannot be higher than 1!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade cannot be lower than 150!";
}

Bureaucrat::Bureaucrat(std::string const& name, const unsigned int n)
  : name(name), grade(n) {
  if (grade > 150) throw Bureaucrat::GradeTooLowException();
  else if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade) {
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    else if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator++() {
  if (grade <= 1) throw Bureaucrat::GradeTooHighException();
  grade -= 1;
  return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
  if (grade <= 1) throw Bureaucrat::GradeTooHighException();
  Bureaucrat result(name, grade--);
  return result;
}

Bureaucrat& Bureaucrat::operator--() {
  if (grade >= 150) throw Bureaucrat::GradeTooLowException();
  grade += 1;
  return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
  if (grade >= 150) throw Bureaucrat::GradeTooLowException();
  Bureaucrat result(name, grade++);
  return result;
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b) {
  return out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
