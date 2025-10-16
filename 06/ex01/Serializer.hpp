/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:49:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/16 16:01:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer {
  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
  private:
    Serializer();
    Serializer(Serializer const& other);
    Serializer& operator=(Serializer const& other);
    ~Serializer();
};

std::ostream& operator<<(std::ostream& out, Data const& x);

#endif
