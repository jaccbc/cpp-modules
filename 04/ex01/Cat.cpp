/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/29 18:13:52 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), self(NULL) {
	type = "Cat";
	try {
		self = new Brain;
		std::cout << "It's a " << type << "! 🐱";
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& error) {
		std::cerr << type << " brain allocation failure: " << error.what();
		std::cerr << std::endl;
	}
}

Cat::Cat(const Cat& other) : Animal(other), self(NULL) {
	try {
		self = new Brain;
		std::cout << type << " has been cloned. 🐱";
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& error) {
		std::cerr << type << " brain allocation failure: " << error.what();
		std::cerr << std::endl;
	}
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		type = other.type;
		delete self;
		try {
			self = new Brain(*other.self);
		}
		catch (const std::bad_alloc& error) {
		  self = NULL;
		  std::cerr << type << " brain allocation failure: " << error.what();
		  std::cerr << std::endl;
		}
	}
	std::cout << type << " has been copied. 🐱";
	std::cout <<  std::endl;
	return *this;
}

Cat::~Cat() {
	delete self;
	std::cout << type << " has fallen! 🐱";
	std::cout << std::endl;
}

void	Cat::makeSound() const {
	std::cout << type << " meows! 🐱";
	std::cout << std::endl;
}
