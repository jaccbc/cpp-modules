/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:27:28 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/18 15:14:34 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <sstream>

// helper template function to display container's contents
template <typename T>
void easyprint(T const& c) {
  for (typename T::const_iterator i = c.begin(); i != c.end(); i++) {
    std::cout << "Index[" << std::distance(c.begin(), i) << "] = "
      << *i << std::endl;
  }
}

/*
  gets a set a of numbers from the user input
  streams those numbers individually to the container
  prints the container content before entering the try/catch block
  asks the user to enter a number to find inside the container
  uses std::distance to calculate the index number by measuring
  the length of from the beginning of the container to the first occurrence
*/
int main() {
  std::cout << "Module 08 | Exercise 00" << std::endl;
  std::cout << "Enter a list of integers separated by spaces: ";
  std::string input;
  std::getline(std::cin, input);
  std::istringstream iss(input);
  int n;
  std::vector<int> a;
  //std::list<int> a;
  //std::deque<int> a;
  while (iss >> n)
    a.push_back(n);
  iss.clear();
  easyprint(a);
  try {
    std::cout << "Enter the integer to be found: ";
    std::getline(std::cin, input);
    iss.str(input);
    iss >> n;
    std::cout << "First index occurrence: "
      << std::distance(a.begin(), easyfind(a, n)) << std::endl;
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
