/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:33:33 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/11 10:47:26 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

/*
  examples of functions with const reference arguments
*/

template <typename T>
void  print(T const& x) {
  std::cout << "[" << x << "]\t";
}

template <typename T>
void isPair(T const& x) {
  print(x);
  std::cout << std::string(x % 2 ? "false" : "true") << std::endl;
}

/*
  examples of functions with const reference arguments
*/

template <typename T>
void add42(T& x) { x += 42; }

// batch of examples (const & non-const)
int main() {
  std::cout << "Module 07 | Exercise 01" << std::endl;
  long a[] = { 52, -352, 51, -4206 };
  const size_t len = sizeof(a) / sizeof(*a);
  iter(a, len, isPair<long>);
  iter(a, len, add42<long>);
  iter(a, len, isPair<long>);
  return 0;
}
