/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:52:11 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/11 12:41:07 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
  std::cout << "Module 07 | Exercise 02" << std::endl;
  Array<std::string> text(3);
  Array<long long> test(1);
  Array<std::string> c(text);
  try {
    c[0] = "Born";
    c[1] = "To";
    c[2] = "Code";
    text[1] = "My new string";
    test[1] = 32;
  }
  catch (std::exception const& e) {
    std::cout << "Exception | " << e.what() << std::endl;
  }
  std::cout << text << std::endl;
  std::cout << c << std::endl;
  std::cout << test << std::endl;
  return 0;
}
