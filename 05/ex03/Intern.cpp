/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:59:13 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 21:33:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Wrapper function responsible for creating the Shrubbery form
static AForm* createShrubberyForm(std::string const& target) {
  return new ShrubberyCreationForm(target); }

// Wrapper function responsible for creating the Robotomy form
static AForm* createRobotomyForm(std::string const& target) {
  return new RobotomyRequestForm(target); }

// Wrapper function responsible for creating the Presidential form
static AForm* createPresidentialForm(std::string const& target) {
  return new PresidentialPardonForm(target); }

/*
  initializes the array of structs of formList_t type
  every struct correlates it's string name with a specific function pointer
  responsable for creating the associated Form
*/
const formList_t Intern::formType[3] = {
  {"Shrubbery", &createShrubberyForm},
  {"Robotomy", &createRobotomyForm},
  {"Presidential", &createPresidentialForm}
};

/*
  takes constant reference of a string object ('form') and verifies if the
  string matches any of the valid form names, otherwise throws an exception
  upon a successful match, creates the new specific form and
  returns it's address to an AForm pointer
*/
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

// virtualized function from the std::exception object
const char* Intern::InvalidFormNameException::what() const throw() {
  return "Intern got an invalid form name!";
}

// default object constructor
Intern::Intern() {}

// copy object constructor
Intern::Intern(Intern const& other) { (void)other; }

// overload of assignment operator ( = )
Intern& Intern::operator=(Intern const& other) {
  (void)other;
  return *this;
}

// object ~destructor
Intern::~Intern() {}
