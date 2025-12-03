/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:53:03 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/03 21:44:57 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// getter to return a const reference to a stack of polish math expression
std::vector<int> const& RPN::getStack() const { return notation; }

// getter to return a reference to a stack of polish math expression
std::vector<int>& RPN::myStack() { return notation; }

/*
  private static method to validate a string of operators
  max of 2 operators (op) before a digit or eof
  accepts + - * / and spaces ' '
*/
bool RPN::isValidOperator(std::string const& s) {
  size_t op = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      ++op;
      if (std::isspace(s[i+1]) || !s[i+1]) continue;
      else return false;
    }
    while (std::isspace(s[i])) ++i;
    if (std::isdigit(s[i])) return true;
  }
  return op > 2 ? false : true;
}

/*
  verify the token string
  does not accept sequencial digits nor anything other
  than spaces and valid operators (+ - * /)
  every valid char needs to be separated by spaces
*/
bool RPN::isValidToken(std::string const& token) const {
  if (token.empty())
    return false;
  for (size_t i = 0; i < token.size(); i++) {
    if (std::isdigit(token[i])) {
      if (!std::isspace(token[i+1])) return false;
      if (i && !std::isspace(token[i-1])) return false;
    }
    else if (!RPN::isValidOperator(token.substr(i)))
      return false;
  }
  return true;
}

/*
  object method to perform the required calculation
  based on the op char ( + - * / )
  >> needs further protection for / division 0 <<
*/
void RPN::calc(const char op) {
 if (notation.size() < 2) throw std::invalid_argument("Error");
 int x = 0;
 int right = notation.back(); notation.pop_back();
 int left = notation.back(); notation.pop_back();
 switch (op) {
   case '+': x = left + right; break;
   case '-': x = left - right; break;
   case '*': x = left * right; break;
   case '/': x = left / right; break;
   default :
     notation.push_back(left);
     notation.push_back(right);
     return ;
 }
 notation.push_back(x);
}

// default object constructor
RPN::RPN() {}

// copy object constructor
RPN::RPN(RPN const& other) : notation(other.getStack()) {}

// copy assingment operator
RPN& RPN::operator=(RPN const& other) {
  if (this != &other) notation = other.getStack();
  return *this;
}

// object destructor
RPN::~RPN() {}
