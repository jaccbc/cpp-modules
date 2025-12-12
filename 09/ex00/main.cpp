/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:28:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/11 20:08:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
  checks the validity of the input arguments
  put DB_FILE content into a map container and opens input file
*/
int main(int argc, char** argv) {
  if (argc != 2 || !argv[1][0]) {
    std::cerr << "Error: ./btc <input file>" << std::endl;
    return -1;
  }
  try {
    BitcoinExchange btc;
    btc.dbDebug(argv[1]);
  }
  catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
