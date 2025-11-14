/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:37:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/14 21:55:06 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*
  wrapper function of the container's iterator that the std::stack holds
*/
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
  return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
  return this->c.end();
}

/*
  default object constructor
  initializes the std::stack<T> by default
*/
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

/*
  copy object constructor
  forwards the "other" class to the base class copy constructor
  who also copies the underlying container (MutantStack<T>)
*/
template <typename T>
MutantStack<T>::MutantStack(MutantStack const& other)
  : std::stack<T>(other) {}

/*
  copy assignment operator
  uses the base class overload function operator to copy its contents
*/
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& other) {
  if (this != &other) std::stack<T>::operator=(other);
  return *this;
}

// object ~destructor
template <typename T>
MutantStack<T>::~MutantStack() {}
