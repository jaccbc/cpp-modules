/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:02:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/29 13:32:27 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// returns the number of the grade to sign
unsigned int PresidentialPardonForm::getSignGrade() const { return sign; }

// returns the number of the grade to execute
unsigned int PresidentialPardonForm::getExecGrade() const { return exec; }

// returns a constant string reference of the target variable
std::string const& PresidentialPardonForm::getTarget() const { return target; }

/*
  outputs a message with the object target string
  this function is called by the base function AForm
*/
void PresidentialPardonForm::beExecuted() const {
  std::cout << target << " has been pardoned by Zaphod Beeblebrox.";
  std::cout << std::endl;
}

// default object constructor
PresidentialPardonForm::PresidentialPardonForm()
  : AForm("Presidential", sign, exec), target("Presidential") {}

// parameterized object constructor
PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
  : AForm("Presidential", sign, exec), target(target) {}

/*
  copy object constructor
  initializes an object with 'other' object values
*/
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
  : AForm("Presidential", other.getSignGrade(), other.getExecGrade()), target(other.getTarget()) {}

// copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
  if (this != &other) target = other.getTarget();
  return *this;
}

// object ~destructor
PresidentialPardonForm::~PresidentialPardonForm() {}
