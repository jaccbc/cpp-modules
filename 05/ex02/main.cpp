/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/15 18:03:25 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
  std::cout << "Module 05 | Exercise 02" << std::endl;
  std::string b = "Marvin";
  std::string f = "CC";
  try {
    Bureaucrat master(b, 150);
    RobotomyRequestForm bush(f);
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
