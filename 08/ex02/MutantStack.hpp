/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:28:52 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/15 19:18:44 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <vector>
#include <cstddef>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
    MutantStack();
    MutantStack(MutantStack const& other);
    MutantStack& operator=(MutantStack const& other);
    ~MutantStack();
};

#include "MutantStack.tpp"

#endif
