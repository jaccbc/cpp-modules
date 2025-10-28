/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 10:24:59 by joandre-         ###   ########.fr       */
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

  try {
    Bureaucrat master(std::string("Trillian"), 11);
    Form exam(std::string("Hitchhiker"), 10, 1);
    std::cout << master << std::endl;
    std::cout << exam << std::endl;
    master.signForm(exam);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
