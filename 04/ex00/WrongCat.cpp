/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/27 01:06:13 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "It's a " << type << "! 🐈";
	std::cout << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << type << " has been cloned. 🐈";
	std::cout << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << type << " has been copied. 🐈";
	std::cout <<  std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << type << " has fallen! 🐈";
	std::cout << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << type << "makes wrong meows! 🐈";
	std::cout << std::endl;
}
