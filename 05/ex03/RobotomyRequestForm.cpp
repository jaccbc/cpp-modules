/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:02:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/15 17:54:01 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

unsigned int RobotomyRequestForm::getSignGrade() const { return sign; }

unsigned int RobotomyRequestForm::getExecGrade() const { return exec; }

std::string const& RobotomyRequestForm::getTarget() const { return target; }

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

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
  : AForm("Robotomy", sign, exec), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
  : AForm("Robotomy", other.getSignGrade(), other.getExecGrade()), target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
  if (this != &other) target = other.getTarget();
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
