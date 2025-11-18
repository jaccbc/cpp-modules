/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:23:36 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/18 22:38:31 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define testN 4

/*
  prints all the contents from a container (except maps)
  copies every int to the std::basic_ostream object
  it's protected against containers with one element
*/
template <typename T>
void  printContainer(T const& c) {
  std::cout << "[";
  if (c.empty()) {
    std::cout << "]" << std::endl;
    return;
  }
  typename T::const_iterator last = c.end();
  --last;
  for (typename T::const_iterator i = c.begin(); i != last; i++)
    std::cout << *i << "] [";
  std::cout << *last << "]" << std::endl;
}

/*
  function to instantiate a std::set and return it
  the std::set will be filled with the second values from std::map (int)
  after the user input its strings
*/
std::set<int> testMaps() {
  std::set<int> a;
  std::map<std::string,int> b;
  std::cout << "Input " << testN << " strings to the map container:" << std::endl;
  for (size_t i = 0; i < testN; i++) {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
      i--;
      continue;
    }
    b[input] = std::rand() % 333;
  }
  std::cout << "map CONTENTS >> ";
  for (std::map<std::string,int>::iterator i = b.begin(); i != b.end(); i++) {
    std::cout << "[" << i->first << "]=[" << i->second << "] ";
    a.insert(i->second);
  }
  std::cout << std::endl;
  return a;
}

/*
  batch of tests of Span class
  seeds random number generator with current time [ std::srand(time(NULL)) ]
  tests both sequence and associative containers
*/
int main() {
  std::cout << "Module 08 | Exercise 01" << std::endl;
  Span sp = Span(10);
  try {
    std::srand(time(NULL));
    for (unsigned int i = 0; i < 6; i++)
      sp.addNumber(std::rand() % 133);
    std::cout << "Span sp CONTENTS >> " << sp << std::endl;
    //std::vector<int> a;
    //std::list<int> a;
    //std::deque<int> a;
    std::set<int> a = testMaps(); // tests both associative containers
    std::cout << "Container a CONTENTS >> ";
    //for (size_t i = 0; i < testN; i++)
    //  a.push_back(std::rand() % 233); // std::vector, std::list, std::deque
    printContainer(a);
    sp.fillSpan(a.begin(), a.end());
    std::cout << "\nSpan sp CONTENTS >> " << sp << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch (std::exception const& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
