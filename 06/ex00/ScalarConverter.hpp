/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:28:43 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/16 13:23:36 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

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
  scalar type;
  double value;
  bool v[3];
} t_scal;

#endif
