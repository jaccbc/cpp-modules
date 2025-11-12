/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:27:28 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/12 16:54:46 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <sstream>

int main() {
  std::cout << "Module 08 | Exercise 00" << std::endl;
  std::cout << "Enter a list of integers separated by spaces: ";
  std::string input;
  std::getline(std::cin, input);
  std::istringstream iss(input);
  int n;
  std::deque<int> a;
  while (iss >> n)
    a.push_back(n);
  easyprint(a);
  try {
    std::cout << "Enter the integer to be found: ";
    std::getline(std::cin, input);
    iss.clear();
    iss.str(input);
    iss >> n;
    easyfind(a, n);
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
