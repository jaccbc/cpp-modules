/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/16 02:42:38 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
  std::cout << "Module 05 | Exercise 03" << std::endl;
  std::string b = "Marvin";
  std::string f = "Robotomy";
  Bureaucrat master(std::string("Boss"), 100);
  Intern random;
  AForm* form = random.makeForm(f, b);
  try {
    form->execute(master);
    std::cout << *form << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl; 
  }
  delete form;
  return 0;
}
