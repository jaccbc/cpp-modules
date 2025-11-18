/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:28:24 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/18 15:10:02 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& c, int n) {
  typename T::iterator i = std::find(c.begin(), c.end(), n);
  if (i == c.end())
    throw std::invalid_argument("Not found!");
  return i;
}

#endif
