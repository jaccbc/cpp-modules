/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:52:11 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/10 14:47:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
  std::cout << "Module 07 | Exercise 02" << std::endl;
  Array<std::string> text(3);
  text[1] = "My new string";
  Array<long long> test(1);
  std::cout << text << std::endl;
  std::cout << test << std::endl;
  return 0;
}
