/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:24:01 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/15 19:19:29 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iterator>

class Span {
  private:
    unsigned int max;
    unsigned int size;
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
    void fillSpan(std::vector<int>::iterator begin,
      std::vector<int>::iterator end);
    int operator[](const size_t i);
    Span(unsigned int N);
    Span(Span const& other);
    Span& operator=(Span const& other);
    ~Span();
};

std::ostream& operator<<(std::ostream& out, Span& put);

#endif
