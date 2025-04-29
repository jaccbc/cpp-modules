/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/25 23:56:11 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << type << " has born! 🍼";
	std::cout << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
		std::cout << type << " has been cloned. 🐾";
		std::cout << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << type << "has been copied. 👀";
	std::cout <<  std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << type << " died! ☠️";
	std::cout << std::endl;
}

std::string	Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << type << " makes a sound 🔊";
	std::cout << std::endl;
}
