/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:49:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/16 16:14:20 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// takes a pointer and converts it to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

// takes an uintptr_t and converts it to a pointer to Data object class
Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

// default object constructor
Serializer::Serializer() {}

// copy object constructor
Serializer::Serializer(Serializer const& other) {
  static_cast<void>(other);
}

// overload of assaignment operator ( = )
Serializer& Serializer::operator=(Serializer const& other) { 
  static_cast<void>(other);
  return *this;
}

// object ~destructor
Serializer::~Serializer() {}

/*
  overload of insertion operator ( << )
  prints all Data from the struct to the std::ostream object
*/
std::ostream& operator<<(std::ostream& out, Data const& x) {
  return out << "username: " << x.username
    << "\npassword: " << x.password << std::endl;
}
