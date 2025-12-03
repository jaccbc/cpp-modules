/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:51:12 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/03 22:32:10 by joandre-         ###   ########.fr       */
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
    static bool isValidOperator(std::string const&);
  public:
    bool isValidToken(std::string const&) const;
    std::vector<int> const& getVector() const;
    std::vector<int>& myVector();
    void calc(const char);
    RPN();
    RPN(RPN const&);
    RPN& operator=(RPN const&);
    ~RPN();
};
#endif

