/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:28:04 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/28 01:05:02 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
  checks the validity of the input arguments
  put DB_FILE content into a map container and opens input file
*/
int main(int argc, char** argv) {
  if (argc != 2 || !argv[1][0])
    return std::cout << "Error: ./btc <input file>" << std::endl, -1;
  BitcoinExchange btc;
  try {
    btc.dbDebug(argv[1]);
  }
  catch (std::exception const& e) {
    return std::cout << "Error: " << e.what() << std::endl, -2;
  }
  return 0;
}
