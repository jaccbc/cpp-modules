/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:27:51 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/18 23:06:58 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

/*
  batch of tests with subject main() code
  and assurance tests for other containers
*/
int main() {
  std::cout << "Module 08 | Exercise 02" << std::endl;
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::const_iterator it = mstack.begin();
  MutantStack<int>::const_iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }

  MutantStack<int> s(mstack);
  /* Here starts the output test for other containers */
  std::cout << "********************" << std::endl;
  std::deque<int> m;

  m.push_back(5);
  m.push_back(17);

  std::cout << m.back() << std::endl;

  m.pop_back();

  std::cout << m.size() << std::endl;

  m.push_back(3);
  m.push_back(5);
  m.push_back(737);
  m.push_back(0);

  std::deque<int>::const_iterator mit = m.begin();
  std::deque<int>::const_iterator mite = m.end();

  ++mit;
  --mit;
  while (mit != mite)
  {
    std::cout << *mit << std::endl;
    ++mit;
  }

  return 0;
}
