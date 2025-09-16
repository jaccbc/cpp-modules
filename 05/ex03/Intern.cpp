/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:59:13 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/16 02:30:27 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm* createShrubberyForm(std::string const& target) {
  return new ShrubberyCreationForm(target); }

static AForm* createRobotomyForm(std::string const& target) {
  return new RobotomyRequestForm(target); }

static AForm* createPresidentialForm(std::string const& target) {
  return new PresidentialPardonForm(target); }

const formList Intern::formType[3] = {
  {"Shrubbery", &createShrubberyForm},
  {"Robotomy", &createRobotomyForm},
  {"Presidential", &createPresidentialForm}
};

AForm* Intern::makeForm(std::string const& form, std::string const& target) const {
  for (unsigned int i = 0; i < 3; i++) {
    if (formType[i].name == form) {
      std::cout << "Intern creates " << form << " form.";
      std::cout << std::endl;
      return formType[i].newForm(target);
    }
  }
  throw InvalidFormNameException();
}

const char* Intern::InvalidFormNameException::what() const throw() {
  return "Intern got an invalid form name!";
}

Intern::Intern() {}

Intern::Intern(Intern const& other) { (void)other; }

Intern& Intern::operator=(Intern const& other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}
