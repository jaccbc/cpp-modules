/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:46:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/01 04:39:46 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  std::cout << "Module 05 | Exercise 00" << std::endl;

  std::string name = "Marvin";
  try {
    Bureaucrat master(name, 01);
    while (true)
      std::cout << master++ << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  } 
  return 0;
}
