/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:48:40 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/05 12:13:51 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
  initilizes a Data struct with 2 strings
  uses the reinterpret_cast to 'serialize' and 'deserialize' the struct
  ends up printing all the Data struct contents
*/
int main() {
  Data secrets = { "", "" };
  for (unsigned int i = 0; i < 2; i++) {
    if (i) std::cout << "Enter password: ",
      getline(std::cin, secrets.password);
    else std::cout << "Enter username: ",
      getline(std::cin, secrets.username);
    std::cout << std::endl;
  };
  std::cout << "Data secrets address: " << &secrets
    << "\nSerialized Number: Ox"
    << std::hex << Serializer::serialize(&secrets)
    << "\nDeserialized Number: "
    << Serializer::deserialize(Serializer::serialize(&secrets))
    << "\n[TOP SECRET]\n"
       "username: "
    << (*Serializer::deserialize(Serializer::serialize(&secrets))).username
    << "\npassword: "
    << (*Serializer::deserialize(Serializer::serialize(&secrets))).password
    << std::endl;
  return 0;
}
