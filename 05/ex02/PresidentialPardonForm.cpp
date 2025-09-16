/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:02:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/15 17:06:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

unsigned int PresidentialPardonForm::getSignGrade() const { return sign; }

unsigned int PresidentialPardonForm::getExecGrade() const { return exec; }

std::string const& PresidentialPardonForm::getTarget() const { return target; }

void PresidentialPardonForm::beExecuted() const {
  std::cout << target << " has been pardoned by Zaphod Beeblebrox.";
  std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
  : AForm("Presidential", sign, exec), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
  : AForm("Presidential", other.getSignGrade(), other.getExecGrade()), target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
  if (this != &other) target = other.getTarget();
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
