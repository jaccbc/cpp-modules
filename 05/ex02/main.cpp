/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 17:29:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
  tries to instantiate 2 objects
  increments the Bureaucrat grade value until it's equal to 1
  sign the form and execute it
  all instatiations and member functions throw exceptions if need
*/
int main() {
  std::cout << "Module 05 | Exercise 02" << std::endl;
  std::string b = "Marvin";
  std::string f = "CC";
  try {
    Bureaucrat master(b, 150);
    ShrubberyCreationForm bush(f);
    while (master.getGrade() != 1) ++master;
    master.signForm(bush);
    bush.beExecuted();
    std::cout << bush << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl; 
  }
  return 0;
}
