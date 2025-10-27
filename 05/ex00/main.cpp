/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/27 19:53:57 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
  Attempts to create a Bureaucrat
  loops forever until a grade boundary exception is thrown
  
*/
int main() {
  std::cout << "Module 05 | Exercise 00" << std::endl;

  try {
    for (Bureaucrat master(std::string("Arthur"), 10); true; master++)
      std::cout << master << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  } 
  try {
    for (Bureaucrat master(std::string("Ford"), 142); true; --master)
      std::cout << master << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
