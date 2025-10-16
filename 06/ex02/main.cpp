/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:16:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/16 17:20:37 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
  allocates a string in the heap and uses his memory address
  to seed the rand() function
  assigns 3 uint16_t values to a, b, c
  the greater value win and returns it's associated object
*/
Base* generate(void) {
  std::string* ram = new std::string("I seed Random Access Memory");
  if (!ram) {
    std::cout << "You have no RAM!" << std::endl;
    return NULL;
  }
  uintptr_t addr = reinterpret_cast<uintptr_t>(&ram);
  std::srand(addr);
  delete ram;
  int16_t a = std::rand();
  std::srand(addr / a);
  int16_t b = std::rand();
  std::srand(addr / b);
  int16_t c = std::rand();
  if (a >= b && a >= c) return new A();
  else if (b >= a && b >= c) return new B();
  else return new C();
}

/*
  uses dynamic_cast to assign a value to each pointer
  only the dynamic_cast of the actual object pointed to by p
  will return an address, every other cast will return NULL
*/
void identify(Base* p) {
  std::cout << "Object pointed to by p = ";
  if (dynamic_cast<A*>(p))
    std::cout << "A";
  else if (dynamic_cast<B*>(p))
    std::cout << "B";
  else if (dynamic_cast<C*>(p))
    std::cout << "C";
  else
    std::cout << "None";
  std::cout << std::endl;
}

/*
  tries to catch exceptions from the dynamic_cast
  ultimately identifying the valid object type when
  the function don't throw an exception
*/
void identify(Base& p) {
  std::cout << "Object referenced by p = ";
  try {
    dynamic_cast<A&>(p);
    std::cout << "A";
  }
  catch (std::exception &e) {
    try {
      dynamic_cast<B&>(p);
      std::cout << "B";
    }
    catch (std::exception &e) {
      try {
        dynamic_cast<C&>(p);
        std::cout << "C";
      }
      catch (std::exception &e) {
        std::cout << "None";
      }
    }
  }
  std::cout << std::endl;
}

/*
  generate() a random derived object class
  identifies the derived object through
  a Base* and a Base&
*/
int main() {
  Base* p = generate();
  identify(p);
  identify(*p);
  delete p;
  return 0;
}
