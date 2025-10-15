/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:02:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 17:25:48 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// returns the number of the grade to sign
unsigned int RobotomyRequestForm::getSignGrade() const { return sign; }

// returns the number of the grade to execute
unsigned int RobotomyRequestForm::getExecGrade() const { return exec; }

// returns a constant string reference of the target variable
std::string const& RobotomyRequestForm::getTarget() const { return target; }

/*
  outputs a message with the object target string
  this function is called by the base function AForm
  randomizes the output by verifying if the number return by rand() is pair
  seeds the random number genarator with the current time of execution
*/
void RobotomyRequestForm::beExecuted() const {
  std::srand(std::time(NULL));
  std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
  std::cout << std::endl;
  std::cout << "* Bzzzzzz… whirrrrr… clank! … drill… drill… drill…    *";
  std::cout << std::endl;
  std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
  std::cout << std::endl;
  std::cout << target;
  if (std::rand() % 2)
    std::cout << " has been robotomized successfully 50% of the time.";
  else
    std::cout << " robotomy failed!";
  std::cout << std::endl;
}

// default object constructor
RobotomyRequestForm::RobotomyRequestForm()
  : AForm("Robotomy", sign, exec), target("RobotomyRequestForm") {}

// parameterized object constructor
RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
  : AForm("Robotomy", sign, exec), target(target) {}

/*
  copy object constructor
  initializes an object with 'other' object values
*/
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
  : AForm("Robotomy", other.getSignGrade(), other.getExecGrade()),
    target(other.getTarget()) {}

// overload of assignment operator ( = )
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
  if (this != &other) target = other.getTarget();
  return *this;
}

// object ~destructor
RobotomyRequestForm::~RobotomyRequestForm() {}
