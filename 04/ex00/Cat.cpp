/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/27 01:05:44 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "It's a " << type << "! 🐱";
	std::cout << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << type << " has been cloned. 🐱";
	std::cout << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << type << " has been copied. 🐱";
	std::cout <<  std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << type << " has fallen! 🐱";
	std::cout << std::endl;
}

void	Cat::makeSound() const {
	std::cout << type << " meows! 🐱";
	std::cout << std::endl;
}
