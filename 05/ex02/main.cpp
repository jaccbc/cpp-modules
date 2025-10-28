/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 12:27:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
  an example in each 3 of the try and catch blocks
  the sign/execution can either be performed by a Bureaucrat
  or an AForm derived class
*/
int main() {
  std::cout << "Module 05 | Exercise 02" << std::endl;

  unsigned int grade = 0;
  try {
    ShrubberyCreationForm exam(std::string("Galaxy"));
    std::cout << exam << std::endl;
    std::cout << "Bureaucrat grade = ";
    std::cin >> grade;
    Bureaucrat master(std::string("Zaphod"), grade);
    master.signForm(exam);
    master.executeForm(exam);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl; 
  }
  std::cout << std::endl;
  try {
    PresidentialPardonForm exam(std::string("Universe"));
    std::cout << exam << std::endl;
    std::cout << "Bureaucrat grade = ";
    std::cin >> grade;
    Bureaucrat master(std::string("Ford"), grade);
    exam.beSigned(master);
    std::cout << exam.getName() << " form was signed by " << master.getName();
    std::cout << std::endl;
    exam.execute(master);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl; 
  }
  std::cout << std::endl;
  try {
    RobotomyRequestForm exam(std::string("The Computer"));
    std::cout << exam << std::endl;
    std::cout << "Bureaucrat grade = ";
    std::cin >> grade;
    Bureaucrat master(std::string("Eddie"), grade);
    master.signForm(exam);
    exam.execute(master);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl; 
  }
  return 0;
}
