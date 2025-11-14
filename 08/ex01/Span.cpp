/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:34:24 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/14 12:17:38 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// returns the maximum number the Span class will hold
unsigned int Span::getMax() const { return max; }

// returns the number of integers the Span class actually holds
unsigned int Span::getSize() const { return size; }

// returns a reference of the object vector<int>
std::vector<int> const& Span::getVector() const { return N; }

// wrapper function to return the std::vector<int>::iterator begin()
std::vector<int>::iterator Span::begin() { return N.begin(); }

// wrapper function to return the std::vector<int>::iterator end()
std::vector<int>::iterator Span::end() { return N.end(); }

/* 
  adds an integer to the std::vector<int>
  if there's no more space to insert numbers an exception is thrown
*/
void Span::addNumber(const int n) {
  if (size >= max) throw std::out_of_range("No more space left!");
  ++size;
  N.push_back(n);
}

/*
  returns the shortest span between all the numbers stored
  creates a temporary vector object to sort it
  without changing the original
  analyzes the temporary sorted vector to find the minimum gap
*/
size_t Span::shortestSpan() const {
  if (size <= 1) throw std::logic_error("No span can be found!");
  std::vector<int> temp(N);
  std::sort(temp.begin(), temp.end());
  size_t diff = static_cast<size_t>(-1);
  for (size_t i = 1; i < temp.size(); i++) {
    size_t gap = temp[i] - temp[i-1];
    if (gap < diff) diff = gap;
  }
  return diff;
}

/*
  returns the longest span between all the numbers stored
  max and min recieve the value from an iterator
  conversion from signed to unsigned is implicit on return statement
*/
size_t Span::longestSpan() const {
  if (size <= 1) throw std::logic_error("No span can be found!");
  int max = *std::max_element(N.begin(), N.end());
  int min = *std::min_element(N.begin(), N.end());
  return max - min;
};

/*
  fills the vector<int> with the range of iterators (begin - end)
  measures the number of elements with std::distance
  if this length + the current number of integers the vector holds
  is greater than it's max capacity (assigned at constructor time)
  an exception is thrown, otherwise fills the vector with std::copy
  and std::back_inserter
*/
void Span::fillSpan(std::vector<int>::iterator begin,
  std::vector<int>::iterator end) {
  size_t len = std::distance(begin, end);
  if (size + len > max)
    throw std::out_of_range("The range is too big to fit!");
  size += len;
  std::copy(begin, end, std::back_inserter(N));
}

// overload of substract operator (wrapper function to vector<int>)
int Span::operator[](const size_t i) {
  if (i >= size) throw std::out_of_range("Index is out of bounds!");
  return N[i];
}

// default object constructor
Span::Span(unsigned int n) : max(n), size(0) { N.reserve(n); }

// copy object constructor
Span::Span(Span const& other) : max(other.getMax()), size(other.getSize()),
  N(other.getVector()) {}

// copy assignment operator
Span& Span::operator=(Span const& other) {
  if (this != &other) {
    max = other.getMax();
    size = other.getSize();
    N = other.getVector();
  }
  return *this;
}

// object ~destructor
Span::~Span() {}

// prints all the numbers the class currently holds
std::ostream& operator<<(std::ostream& out, Span& put) {
  for (size_t i = 0; i < put.getSize(); i++)
    out << "[" << put[i] << "] ";
  return out;
}
