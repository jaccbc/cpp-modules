/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:27:51 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/14 21:41:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

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

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }

  MutantStack<int> s(mstack);
  return 0;
}
