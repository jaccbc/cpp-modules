/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:31:39 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/30 13:56:13 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// checks if the string literal is a character
static bool isChar(std::string const& s) {
  return s.size() == 3 && s.at(0) == '\'' && s.at(2) == '\'';
}

// checks if the string literal is an int
static bool isInt(std::string const& s) {
  size_t i = 0;
  if (s[i] == '+' || s[i] == '-') i = 1;
  if (!s[i]) return false;
  while (std::isdigit(static_cast<unsigned char>(s[i])))
    ++i;
  if (s[i]) return false;
  return true;
}

/*
  checks if the string literal is of fractional type (FLOAT / DOUBLE)
  the checks are based on the enum scalar type given as an argument
  to be a type DOUBLE it needs to have a sigle dot
  floats need to end with 'f'
*/
static bool isFractional(scalar type, std::string const& s) {
  size_t len = s.size();
  if (len == 1) return false;
  if (type == FLOAT) {
    --len;
    if (s.at(len) != 'f'
      || !std::isdigit(static_cast<unsigned char>(s.at(len - 1))))
      return false;
  }
  size_t i = 0;
  if ((s.at(i) == '-' || s.at(i) == '+')) {
    if (!std::isdigit(static_cast<unsigned char>(s.at(++i))))
      return false;
  }
  bool dot = false;
  while (i < len) {
    if (!dot && s.at(i) == '.') {
      dot = true;
      ++i;
    }
    else if (dot && s.at(i) == '.') return false;
    if (!std::isdigit(static_cast<unsigned char>(s.at(i++))))
      return false;
  }
  if (type == DOUBLE && !dot) return false;
  return true;
}

// prints every scalar type as imposible
static void printImpossible() {
  std::cout << "char: impossible\n"
  "int: impossible\n"
  "float: impossible\n"
  "double: impossible" << std::endl;
}

/*
  finds the first dot ('.') in the string
  which delimits the precision count
  if no dot is found returns 1 as the precision number
  iterates from the end of the string to the first dot
  first loop ignores the last sequence of zeros
  second loop measures precision
*/
static size_t findPrecision(scal_t conv) {
  size_t p = 0;
  size_t d = conv.numb.find('.');
  if (d == std::string::npos) return 1;
  size_t i = conv.numb.size() - 1;
  if (conv.type == FLOAT) --i;
  while (i > d && conv.numb[i] == '0') --i;
  while (i > d) {
	++p;
	--i;
  }
  if (p) return p;
  return 1;
}

/*
  verify the flags for each scalar conversion
  CHAR/INT v[0], FLOAT v[1] and DOUBLE v[2]
  prints a value if true and impossible/Non displayable if false
*/
static void printConversion(scal_t conv) {
  std::cout << "char: ";
  if (conv.v[0] && conv.value >= std::numeric_limits<char>::min()
    && conv.value <= std::numeric_limits<char>::max()) {
    if (std::isprint(static_cast<unsigned char>(conv.value)))
      std::cout << static_cast<char>(conv.value);
    else
      std::cout << "Non displayable";
  }
  else std::cout << "impossible";
  std::cout << std::endl;
  std::cout << "int: ";
  if (conv.v[0]) std::cout << static_cast<int>(conv.value);
  else std::cout << "impossible";
  std::cout << std::endl;
  std::cout << std::fixed;
  if (conv.type == CHAR || conv.type == INT)
    std::cout << std::setprecision(1);
  else std::cout << std::setprecision(findPrecision(conv));
  std::cout << "float: ";
  if (conv.v[1]) std::cout << static_cast<float>(conv.value) << "f";
  else std::cout << "impossible";
  std::cout << std::endl;
  std::cout << "double: ";
  if (conv.v[2]) {
    if (conv.type == FLOAT) std::cout << static_cast<float>(conv.value);
    else std::cout << conv.value;
  }
  else std::cout << "impossible";
  std::cout << std::endl;
}

// handles the string literal as a CHAR scalar type conversion
static void handleChar(std::string const& s) {
  scal_t conv = {
	s,
    CHAR,
    static_cast<double>(s.at(1)),
    { true, true, true } 
  };
  printConversion(conv);
}

/*
  handles the string literal as an INT scalar type conversion
  uses the std::istringstream object to convert the string literal to a number
  sets the failbit value to catch exceptions from the stream conversion
  prints impossible if an exception is catch or if the number goes out of bounds
*/
static void handleInt(std::string const& s) {
  scal_t conv = { s, INT, 0, { true, true, true } };
  std::istringstream iss(s);
  iss.exceptions(std::ios::failbit);
  try { iss >> conv.value; }
  catch (std::ios_base::failure& e) {
    printImpossible();
    return;
  }
  if (conv.value < std::numeric_limits<int>::min()
    || conv.value > std::numeric_limits<int>::max()) {
    printImpossible();
    return;
  }
  printConversion(conv);
}

/*
  handles the string literal as a FLOAT scalar type conversion
  uses the std::istringstream object to convert the string literal to a number
  sets the failbit value to catch exceptions from the stream conversion
  if the conversion to INT goes out of bounds,
  the bool flag 'conv.v[0]' is modified to false
*/
static void handleFloat(std::string const& s) {
  scal_t conv = { s, FLOAT, 0, { true, true, true } };
  std::istringstream iss(s);
  iss.exceptions(std::ios::failbit);
  try { iss >> conv.value; }
  catch (std::ios_base::failure& e) {
    printImpossible();
    return ;
  }
  if (conv.value < -std::numeric_limits<float>::max()
    || conv.value > std::numeric_limits<float>::max()) {
    printImpossible();
    return;
  }
  if (conv.value < std::numeric_limits<int>::min()
    || conv.value > std::numeric_limits<int>::max())
    conv.v[0] = false;
  printConversion(conv);
}

/*
  handles the string literal as a DOUBLE scalar type conversion
  uses the std::istringstream object to convert the string literal to a number
  sets the failbit value to catch exceptions from the stream conversion
  if the conversion to INT and FLOAT goes out of bounds,
  the bool flag 'conv.v[0]' && 'conv.v[1]' is modified to false
*/
static void handleDouble(std::string const& s) {
  scal_t conv = { s, DOUBLE, 0, { true, true, true } };
  std::istringstream iss(s);
  iss.exceptions(std::ios::failbit);
  try { iss >> conv.value; }
  catch (std::ios_base::failure& e) {
    printImpossible();
    return ;
  }
  if (conv.value < std::numeric_limits<int>::min()
    || conv.value > std::numeric_limits<int>::max())
    conv.v[0] = false;
  if (conv.value < -std::numeric_limits<float>::max()
    || conv.value > std::numeric_limits<float>::max())
    conv.v[1] = false;
  printConversion(conv);
}

/*
  if the string literal is empty the function halts execution
  verifies what type of scalar conversion type the string literal holds
  and handles it accordingly, otherwise prints everything as impossible
  (infinite and non a number values included)
*/
void ScalarConverter::convert(std::string const& lit) {
  if (lit.empty()) {
    std::cout << "Error: empty string" << std::endl;
    return ;
  }
  if (isChar(lit)) handleChar(lit);
  else if (isInt(lit)) handleInt(lit);
  else if (isFractional(FLOAT, lit)) handleFloat(lit);
  else if (isFractional(DOUBLE, lit)) handleDouble(lit);
  else printImpossible();
}

// default object constructor
ScalarConverter::ScalarConverter() {}

// copy object constructor
ScalarConverter::ScalarConverter(ScalarConverter const& other) {
  static_cast<void>(other); }

// copy assignment operator
ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other) {
  if (this != &other) *this = other;
  return *this;
}

// object ~destructor
ScalarConverter::~ScalarConverter() {}
