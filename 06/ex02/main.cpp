/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:16:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/30 17:58:20 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
  first seeds srand() with the current time
  afterwards it seeds srand() with int16_t value previously assigned by rand()
  the greater value win and returns its associated object
*/
Base* generate(void) {
  std::srand(time(NULL));
  int16_t a = std::rand();
  std::srand(a);
  int16_t b = std::rand();
  std::srand(b);
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
  Base& t = p;
  try {
    t = dynamic_cast<A&>(p);
    std::cout << "A";
  }
  catch (std::exception &e) {
    try {
      t = dynamic_cast<B&>(p);
      std::cout << "B";
    }
    catch (std::exception &e) {
      try {
        t = dynamic_cast<C&>(p);
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
