/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:53:03 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/13 18:56:11 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// returns a const reference to a container (vector)
std::vector<int> const& RPN::getVector() const { return notation; }

// returns true if c is a valid operator
bool RPN::isValidOperator(const char c) const {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*
  verify the token string
  does not accept sequencial digits
  accepts spaces and valid operators (+ - * /)
  every valid char needs to be separated by spaces or EOF
*/
bool RPN::isValidToken(std::string const& token) const {
  if (token.empty()) return false;
  for (size_t i = 0; i < token.size(); i++) {
    if (std::isdigit(token[i]) || isValidOperator(token[i])) {
      if (std::isspace(token[i+1]) || token.size() == i+1) continue;
      else return false;
    }
    else if (std::isspace(token[i])) continue;
    else return false;
  }
  return true;
}

/*
  object method to perform the required calculation
  based on the op char ( + - * / )
  op / is safe guarded with division by 0
*/
void RPN::calc(const char op) {
 if (notation.size() < 2)
  throw std::invalid_argument("expression needs at least 2 operands");
 int x = 0;
 int right = notation.back(); notation.pop_back();
 int left = notation.back(); notation.pop_back();
 switch (op) {
   case '+': x = left + right; break;
   case '-': x = left - right; break;
   case '*': x = left * right; break;
   case '/':
     right == 0 ?
     throw std::invalid_argument("division by zero") : x = left / right;
     break;
   default :
     notation.push_back(left);
     notation.push_back(right);
     return ;
 }
 notation.push_back(x);
}

/*
  public method responsible for printing the expression result
  after the calculations a sole number is left in the container (result)
  otherwise the expression is invalid and an exception is thrown
*/
void RPN::run() const {
  if (notation.size() != 1)
    throw std::invalid_argument("invalid Reverse Polish expression");
  std::cout << notation.front() << std::endl;
}

/*
  default object constructor
  takes the const char* expression and make it a string object
  verifies if the token is valid otherwise throws exception
  if valid push the digits back to the container
  and performs the calculations when an operator is found
*/
RPN::RPN(const char* expression) {
  std::string token(expression);
  if (isValidToken(token)) {
    for (size_t i = 0; i < token.size(); i++) {
      while (std::isspace(token[i])) ++i;
      (std::isdigit(token[i])) ?
      (notation.push_back(token[i] - '0')) : (calc(token[i]));
    }
  }
  else throw std::invalid_argument("invalid input");
}

// copy object constructor
RPN::RPN(RPN const& other) : notation(other.getVector()) {}

// copy assingment operator
RPN& RPN::operator=(RPN const& other) {
  if (this != &other) notation = other.getVector();
  return *this;
}

// object destructor
RPN::~RPN() {}
