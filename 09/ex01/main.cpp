/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:51:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/03 22:37:26 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
  only accepts a string argument
  if the string expression is valid pushes the number
  to the back of the container otherwise perferms the arithmetic operation
  if there's more than 1 number left in the container after the string is fully
  read, prints "Error" to the stderr (RPN expression is invalid)
*/
int main(int argc, char** argv) {
  if (argc != 2 || !argv[1][0])
    return std::cerr << "Error: usage ./RPN <expression>" << std::endl, 1;
  RPN a;
  try {
    std::string token(argv[1]);
    if (a.isValidToken(token)) {
      for (size_t i = 0; i < token.size(); i++) {
        while (std::isspace(token[i])) ++i;
        std::isdigit(token[i]) ?
        a.myVector().push_back(token[i] - '0') : a.calc(token[i]);
      }
    }
  }
  catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  if (a.myVector().size() == 1) std::cout << a.myVector().front() << std::endl;
  else return std::cerr << "Error" << std::endl, -1;
  return 0;
}
