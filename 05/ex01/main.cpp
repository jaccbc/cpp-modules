/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 15:47:44 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
  tries to initialize 2 objects (Bureaucrat && Form)
  uses the Bureaucrat object to sign the Form
  throws an exception if any value is out of bounds
  
*/
int main() {
  std::cout << "Module 05 | Exercise 01" << std::endl;
  std::string b = "Marvin";
  std::string f = "CC";
  try {
    Bureaucrat master(b, 121);
    Form test(f, 1, 10);
    master.signForm(test);
    std::cout << master << std::endl;
    std::cout << test << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl; 
  }
  return 0;
}
