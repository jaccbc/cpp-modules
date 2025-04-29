/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/27 01:06:02 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "It's a " << type << "! 🐶";
	std::cout << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << type << " has been cloned. 🐶";
	std::cout << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << type << " has been copied. 🐶";
	std::cout <<  std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << type << " stumbles! 🐶";
	std::cout << std::endl;
}

void	Dog::makeSound() const {
	std::cout << type << " barks! 🐶";
	std::cout << std::endl;
}
