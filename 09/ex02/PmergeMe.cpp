/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:59:12 by joandre-          #+#    #+#             */
/*   Updated: 2026/01/23 14:47:48 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// getter to return the list container
std::list<unsigned int> const& PmergeMe::getList() const { return lst; }

//getter to return the deque container
std::deque<unsigned int> const& PmergeMe::getDeque() const { return deq; }

/*
  gets the input from the program and returns a string copy
  otherwise throws exceptions
*/
std::string PmergeMe::getInput(int argc, char** argv) {
  if (argc == 1)
    throw std::invalid_argument("usage => ./PmergeMe <positive integers>");
  std::string parse;
  for (int c = 1; c < argc; c++) {
    for (size_t i = 0; argv[c][i]; i++) {
      if (!std::isdigit(argv[c][i]) && !std::isspace(argv[c][i]))
        throw std::invalid_argument("only numbers and spaces allwoed!");
    }
    parse += std::string(argv[c]) + " ";
  }
  return parse;
}

size_t PmergeMe::jacobsthal(size_t n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  size_t a = 0, b = 1, c;
  for (size_t i = 2; i <= n; ++i) {
    c = b + 2 * a;
    a = b;
    b = c;
  }
  return b;
}

// responsible to run the algo on both containers
void PmergeMe::run() {
  printContent("Before:", deq);
  std::clock_t d_start = std::clock();
  mergeInsertSort(deq);
  std::clock_t d_end = std::clock();
  std::clock_t l_start = std::clock();
  mergeInsertSort(lst);
  std::clock_t l_end = std::clock();
  printContent("After:", deq);
  std::cout << "Time to process a range of " << deq.size()
  << " elements with std::deque : "
  << static_cast<double>((d_end - d_start)) / CLOCKS_PER_SEC * 1e6
  << " µs" << std::endl;
  std::cout << "Time to process a range of " << lst.size()
  << " elements with std::list : "
  << static_cast<double>((l_end - l_start)) / CLOCKS_PER_SEC * 1e6
  << " µs" << std::endl;
}

/*
  default object constructor
  if any error occurs an exception is thrown
  initializes the seq string with program input numbers
  initializes the stream with seq string
  parses the string to positive integers
*/
PmergeMe::PmergeMe(int argc, char** argv) {
  std::string seq(getInput(argc, argv));
  std::istringstream stream(seq);
  unsigned int x = 0;
  while (stream >> x) {
    deq.push_back(x);
    lst.push_back(x);
  }
  if (!deq.size())
    throw std::invalid_argument("no numbers.");
}

// copy object constructor
PmergeMe::PmergeMe(PmergeMe const& other)
: lst(other.getList()), deq(other.getDeque()) {}

// copy assignment operator
PmergeMe& PmergeMe::operator=(PmergeMe const& other) {
  if (this != &other) {
    lst = other.getList();
    deq = other.getDeque();
  }
  return *this;
}

// object destructor
PmergeMe::~PmergeMe() {}
