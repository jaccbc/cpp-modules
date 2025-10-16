/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:48:40 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/16 16:19:51 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
  initilizes a Data struct with 2 strings
  uses the reinterpret_cast to serialize and deserialize a block of data
  ends up printing all the Data object contents upon a chain of casts
*/
int main() {
  Data d = {
    "joandre-",
    "sEcURE_paSsWOrD"
  };
  std::cout << "Serialized Number: Ox"
    << std::hex << Serializer::serialize(&d)
    << "\nDeserialed Number: "
    << Serializer::deserialize(Serializer::serialize(&d))
    << "\n[TOP SECRET]\n"
    << *Serializer::deserialize(Serializer::serialize(&d)) << std::endl;
  return 0;
}
