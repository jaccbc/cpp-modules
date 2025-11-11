/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:53:06 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/11 12:15:06 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
  public:
    unsigned int size() const;
    T& operator[](const unsigned int n);
    T const& operator[](const unsigned int n) const;
    Array();
    Array(const unsigned int n);
    Array(Array const& other);
    Array& operator=(Array const& other);
    ~Array();
  private:
    T* a;
    unsigned int len;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Array<T> const& a);

#include "Array.tpp"

#endif
