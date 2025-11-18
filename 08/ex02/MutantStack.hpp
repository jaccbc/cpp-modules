/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:28:52 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/18 23:07:38 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <cstddef>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T> {
  public:
    typedef typename
      std::stack<T>::container_type::iterator iterator;
    typedef typename
      std::stack<T>::container_type::const_iterator const_iterator;
    iterator begin();
    iterator end();
    MutantStack();
    MutantStack(MutantStack const& other);
    MutantStack& operator=(MutantStack const& other);
    ~MutantStack();
};

#include "MutantStack.tpp"

#endif
