/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:54:57 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/05 16:07:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
  PmergeMe object recieves input arguments and performs validations
  runs the algorithm afterwards
*/
int main(int argc, char** argv) {
  try {
    PmergeMe prog(argc, argv);
    prog.run();
  }
  catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
