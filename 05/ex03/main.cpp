/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 21:47:51 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*
  tries to create a Bureaucrat obejct, an Intern object
  initializes a pure virutal object pointer (AForm)
  attemtps to execute the form through the pure virtual object pointer
  throws an exception if anything goes beyond the guide rules 
*/
int main() {
  std::cout << "Module 05 | Exercise 03" << std::endl;
  std::string b = "Marvin";
  std::string f = "Robotomy";
  AForm* form = NULL;
  try {
    Bureaucrat master(std::string("Boss"), 100);
    Intern random;
    AForm* form = random.makeForm(f, b);
    try {
      form->execute(master);
      std::cout << *form << std::endl;
      delete form;
    }
    catch (std::exception &e) {
      std::cout << e.what() << std::endl;
      delete form;
    }
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    delete form;
  }
  return 0;
}
