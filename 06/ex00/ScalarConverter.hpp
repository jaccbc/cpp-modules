/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:28:43 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/03 13:09:24 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>

class ScalarConverter {
  public:
    static void convert(std::string const& lit);
  private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const& other);
    ScalarConverter& operator=(ScalarConverter const& other);
    ~ScalarConverter();
};

enum scalar {
  CHAR,
  INT,
  FLOAT,
  DOUBLE
};

typedef struct s_scal {
  std::string const& numb;
  scalar type;
  long double value;
  bool v[3];
} scal_t;

#endif
