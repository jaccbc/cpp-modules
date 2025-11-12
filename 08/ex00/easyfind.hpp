/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:28:24 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/12 16:57:12 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void easyfind(T const& c, int n) {
  typename T::const_iterator i = std::find(c.begin(), c.end(), n);
  if (i == c.end())
    throw std::invalid_argument("No occurance found!");
  else {
    std::cout << "First occurance found at index: "
      << std::distance(c.begin(), i) << std::endl;
  }
}

template <typename T>
void easyprint(T const& c) {
  for (typename T::const_iterator i = c.begin(); i != c.end(); i++) {
    std::cout << "Index[" << std::distance(c.begin(), i) << "] = "
      << *i << std::endl;
  }
}

#endif
