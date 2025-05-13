/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/29 18:13:08 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), self(NULL) {
	type = "Dog";
	try {
		self = new Brain;
		std::cout << "It's a " << type << "! 🐶";
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& error) {
		std::cout << type << " brain allocation failure: " << error.what();
		std::cout << std::endl;
	}
}

Dog::Dog(const Dog& other) : Animal(other), self(NULL) {
	try {
		self = new Brain;
		std::cout << type << " has been cloned. 🐶";
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& error) {
		std::cout << type << " brain allocation failure: " << error.what();
		std::cout << std::endl;
	}
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		type = other.type;
		delete self;
		try {
			self = new Brain(*other.self);
		}
		catch (const std::bad_alloc& error) {
			self = NULL;
			std::cout << type << " brain allocation failure: " << error.what();
			std::cout << std::endl;
		}
	}
	std::cout << type << " has been copied. 🐶";
	std::cout <<  std::endl;
	return *this;
}

Dog::~Dog() {
	delete self;
	std::cout << type << " stumbles! 🐶";
	std::cout << std::endl;
}

void	Dog::makeSound() const {
	std::cout << type << " barks! 🐶";
	std::cout << std::endl;
}
