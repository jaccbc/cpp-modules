/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/28 01:32:01 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), self(NULL) {
	type = "WrongCat";
	try {
		self = new Brain;
		std::cout << "It's a " << type << "! 🐈";
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& error) {
		std::cout << type << " brain allocation failure: " << error.what();
		std::cout << std::endl;
	}
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other), self(NULL) {
	try {
		self = new Brain;
		std::cout << type << " has been cloned. 🐈";
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& error) {
		std::cout << type << " brain allocation failure: " << error.what();
		std::cout << std::endl;
	}
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		type = other.type;
		delete self;
		self = other.self;
	}
	std::cout << type << " has been copied. 🐈";
	std::cout <<  std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	delete self;
	std::cout << type << " has fallen! 🐈";
	std::cout << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << type << " makes wrong meows! 🐈";
	std::cout << std::endl;
}
