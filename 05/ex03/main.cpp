/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 17:13:33 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*
  interactively assigns a grade to the bureuacrat
  output 3 options available to create forms and waits for user input
  uses an abstract class pointer to sign and execute forms
*/
int main() {
  std::cout << "Module 05 | Exercise 03" << std::endl;

  unsigned int grade = 0;
  unsigned int x = 0;
  AForm* form = NULL;
  std::string list[3] = { "Shrubbery", "Robotomy", "Presidential" };
  for (unsigned int i = 0; i < 3; i++) {
    std::cout << "List " << i << " = " << list[i] << std::endl;
  }
  std::cout << "List to create = ";
  std::cin >> x;
  if (x > 2) {
    std::cout << "List index cannot be greater than 2" << std::endl;
    return 1;
  }
  try {
    std::cout << "Bureaucrat grade = ";
    std::cin >> grade;
    Bureaucrat master(std::string("Dent"), grade);
    Intern random;
    form = random.makeForm(list[x], master.getName());
    std::cout << *form << std::endl;
    master.signForm(*form);
    master.executeForm(*form);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete form;
  return 0;
}
