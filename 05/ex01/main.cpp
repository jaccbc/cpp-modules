/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/01 04:39:33 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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
