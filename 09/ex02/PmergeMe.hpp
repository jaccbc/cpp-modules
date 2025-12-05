/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/05 17:25:43 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe {
  private:
    std::list<unsigned int> lst;
    std::deque<unsigned int> deq;
    std::string getInput(int, char**);
    // template function to print container contents (list/deque)
    template <typename T>
    void printContent(const char* prefix, T const& container) const {
      std::cout << prefix;
      for (typename T::const_iterator it = container.begin();
      it != container.end(); it++) {
        std::cout << " " << *it;
      }
      std::cout << std::endl;
    };
    /*
      template function to compare 2 numbers and split them
      into 2 containers (main for big, pend for small)
    */
    template <typename T>
    void pairSort(T const& src, T& main, T& pend) {
      typename T::const_iterator it = src.begin();
      while (it != src.end()) {
        unsigned int a = *it++;
        unsigned int b = it == src.end() ? 0 : *it;
        if (it++ == src.end()) { main.push_back(a); break; }
        (a > b) ? (main.push_back(a), pend.push_front(b))
        : (main.push_back(b), pend.push_front(a));
      }
    }
    /*
      template function to recursively sort numbers after
      comparing all in subsets of 2's
    */
    template <typename T>
    void mergeInsertSort(T& container) {
      if (container.size() <= 1) return;
      T main, pend;
      pairSort(container, main, pend);
      mergeInsertSort(main);
      for (typename T::reverse_iterator it = pend.rbegin();
      it != pend.rend(); it++) {
        typename T::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
        main.insert(pos, *it);
      }
      container.swap(main);
    };
  public:
    void run();
    std::list<unsigned int> const& getList() const;
    std::deque<unsigned int> const& getDeque() const;
    PmergeMe(int, char**);
    PmergeMe(PmergeMe const&);
    PmergeMe& operator=(PmergeMe const&);
    ~PmergeMe();
};

#endif
