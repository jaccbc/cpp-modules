/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:56:03 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/10 15:04:33 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// gets the size of the array
template <typename T>
unsigned int Array<T>::size() const { return len; }

/*
  overload of square bracker operator[]
  mimics an array-like access
  gets the indexed value in the specified position
  if an invalid index is attempted to be reached, an exception is thrown
  const and non-const values definitions
*/
template <typename T>
T& Array<T>::operator[](const unsigned int n) {
  if (n >= len)
    throw std::out_of_range("Array's index out of range");
  return a[n];
}

template <typename T>
T const& Array<T>::operator[](const unsigned int n) const {
  if (n >= len)
    throw std::out_of_range("Array's index out of range");
  return a[n];
}

// default object constructor
template <typename T>
Array<T>::Array() : a(NULL), len(0) {}

// parameterized object constructor
template <typename T>
Array<T>::Array(const unsigned int n) : a(new T[n]()), len(n) {}

// copy object constructor
template <typename T>
Array<T>::Array(Array const& other) : a(new T[other.size()]),
  len(other.size()) {
  for (unsigned int i = 0; i < len; i++)
    a[i] = other.a[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other) {
  if (this != &other) {
    delete[] a;
    len = other.size();
    a = new T[len];
    if (a)
      for (unsigned int i = 0; i < len; i++)
        a[i] = other.a[i];
  }
  return *this;
}

// object ~destructor
template <typename T>
Array<T>::~Array() { delete[] a; };

// overload of insertion operator ( << )
template <typename T>
std::ostream& operator<<(std::ostream& out, Array<T> const& a) {
  for (unsigned int i = 0; i < a.size(); i++)
    out << "[" << a[i] << "] ";
  return out;
}
