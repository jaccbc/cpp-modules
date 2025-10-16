/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:28:11 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/16 13:22:23 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
  the number of arguments passed are verified
  it runs with 1 argument or no argument
  if no argument is given the program enters a loop
  to scalar convert every input passed
*/
int main(int argc, char **argv) {
  if (argc > 2) {
    std::cout << "Usage: ./convert <literal>" << std::endl;
    return 1;
  }
  else if (argc == 2) ScalarConverter::convert(argv[1]);
  else {
    std::cout << "DISCLAIMER: to exit the loop, hit CTRL+D on Linux" 
    " or CTRL+Z on Windows" << std::endl;
    std::string input;
    while (std::cin >> input) {
      ScalarConverter::convert(input);
      std::cout << std::endl;
    }
  }
  return 0;
}
