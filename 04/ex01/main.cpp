/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:11:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/05/13 01:45:06 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const unsigned int n = 3;
	unsigned int m = 0;
	Animal* zoo[n];
	WrongCat* cell[n];
	// WrongAnimal *l = new WrongCat;
	// delete l; // memory leak
	Animal c;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	try {
		for (unsigned int i = 0; i < n / 2; i++) {
			zoo[i] = new Dog;
			++m;
		}
		for (unsigned int i = n / 2; i < n; i++) {
			zoo[i] = new Cat;
			++m;
		}
	}
	catch (const std::bad_alloc& error) {
		for (unsigned int i = 0; i < m; i++)
			delete zoo[i];
		std::cout << "Zoo allocation failure: " << error.what();
		std::cout << std::endl;
		return 1;
	}
	for (unsigned int i = 0; i < n; i++) {
		zoo[i]->makeSound();
		delete zoo[i];
	}
	std::cout << std::endl;
	m = 0;
	try {
		for (unsigned int i = 0; i < n; i++) {
			cell[i] = new WrongCat;
			++m;
		}
	}
	catch (const std::bad_alloc& error) {
		for (unsigned int i = 0; i < m; i++)
			delete cell[i];
		std::cout << "Cell allocation failure: " << error.what();
		std::cout << std::endl;
		return 1;
	}

	for (unsigned int i = 0; i < n; i++) {
		cell[i]->makeSound();
		delete cell[i];
	}
	c.makeSound();
	return 0;
}
