/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:24:01 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/18 22:30:57 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

class Span {
  private:
    unsigned int max;
    std::vector<int> N;
  public:
    unsigned int getMax() const;
    unsigned int getSize() const;
    std::vector<int> const& getVector() const;
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    void addNumber(const int n);
    size_t shortestSpan() const;
    size_t longestSpan() const;
    template <typename T>
    void fillSpan(T begin, T end) {
      size_t len = std::distance(begin, end);
      if (N.size() + len > max)
        throw std::out_of_range("The range is too big to fit!");
      std::copy(begin, end, std::back_inserter(N));
    }
    int operator[](const size_t i) const;
    Span(unsigned int N);
    Span(Span const& other);
    Span& operator=(Span const& other);
    ~Span();
};

std::ostream& operator<<(std::ostream& out, Span const& put);

#endif
