/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:35:50 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/05 23:55:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>

template <typename T>
void swap(T& v1, T& v2) {
  T temp = v1;
  v1 = v2;
  v2 = temp;
};

template <typename T>
T const& min(const T& v1, const T& v2) {
  return v1 > v2 ? v2 : v1;
};

template <typename T>
T const& max(const T& v1, const T& v2) {
  return v1 > v2 ? v1 : v2;
};

#endif
