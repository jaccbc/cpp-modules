/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:23:36 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/14 12:24:03 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
  batch of tests of Span class
  seeds random number generator with current time [ std::srand(time(NULL)) ]
  first loop adds numbers randomly, second one does the same but directly
  to the std::vector<int> to further fill the Span class with its iterators
*/
int main() {
  std::cout << "Module 08 | Exercise 01" << std::endl;
  Span sp = Span(10);
  try {
    std::srand(time(NULL));
    for (unsigned int i = 0; i < 6; i++) {
      sp.addNumber(std::rand());
     }
    std::vector<int> a;
    for (size_t i = 0; i < 4; i++) {
      a.push_back(std::rand() / 200);
      std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }
    sp.fillSpan(a.begin(), a.end());
    std::cout << "[SPAN]\n" << sp << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp[10000000] << std::endl;
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
