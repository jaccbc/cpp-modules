/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:32:07 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/16 14:55:35 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string const& Bureaucrat::getName() const { return name; }

unsigned int Bureaucrat::getGrade() const { return grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade cannot be higher than 1!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade cannot be lower than 150!";
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
