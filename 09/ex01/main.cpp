/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:51:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/12 01:09:04 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
  only accepts 1 argument
  instantiate the RPN object with the input argument
  the object performs validations and calculations
  the run() method outputs the result
*/
int main(int argc, char** argv) {
  if (argc != 2 || !argv[1][0]) {
    std::cerr << "Error: usage ./RPN <expression>" << std::endl;
    return -1;
  }
  try {
    RPN math(argv[1]);
    math.run();
  }
  catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
