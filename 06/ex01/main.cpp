/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:48:40 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/04 00:38:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
  initilizes a Data struct with 2 strings
  uses the reinterpret_cast to 'serialize' and 'deserialize' the struct
  ends up printing all the Data struct contents
*/
int main() {
  Data secrets = {
    "joandre-",
    "sEcURE_paSsWOrD"
  };
  std::cout << "Data secrets: " << &secrets << "\nSerialized Number: Ox"
    << std::hex << Serializer::serialize(&secrets)
    << "\nDeserialized Number: "
    << Serializer::deserialize(Serializer::serialize(&secrets))
    << "\n[TOP SECRET]\n"
    << *Serializer::deserialize(Serializer::serialize(&secrets)) << std::endl;
  return 0;
}
