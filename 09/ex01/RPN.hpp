/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:51:12 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/13 18:26:39 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

class RPN {
  private:
    std::vector<int> notation;
    bool isValidOperator(const char) const;
    bool isValidToken(std::string const&) const;
    void calc(const char);
  public:
    void run() const;
    std::vector<int> const& getVector() const;
    RPN(const char*);
    RPN(RPN const&);
    RPN& operator=(RPN const&);
    ~RPN();
};
#endif

