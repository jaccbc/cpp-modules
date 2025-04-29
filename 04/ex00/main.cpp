/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:11:29 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/27 01:24:14 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {
	std::cout << "[Animal *meta = new Animal()]" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "[Animal *j = new Dog()]" << std::endl;
	const Animal* j = new Dog();
	std::cout << "[Animal *i = new Cat()]" << std::endl;
	const Animal* i = new Cat();
	std::cout << "[WrongAnimal* b = new WrongCat]" << std::endl;
	const WrongAnimal* b = new WrongCat;
	std::cout << "[WrongAnimal* c = new WrongAnimal]" << std::endl;
	const WrongAnimal* c = new WrongAnimal;
	std::cout << "[WrongAnimal* p = new WrongCat]" << std::endl;
	const WrongCat* p = new WrongCat;

	std::cout << "[b->makeSound()]" << std::endl;
	b->makeSound();
	std::cout << "[b->getType() = ]" << b->getType() << std::endl;
	std::cout << "[c->getType() = ]" << c->getType() << std::endl;
	std::cout << "[c->makeSound()]" << std::endl;
	c->makeSound();
	std::cout << "[p->makeSound()]" << std::endl;
	p->makeSound();
	std::cout << "[j->getType() = ]" << j->getType() << std::endl;
	std::cout << "[i->getType() = ]" << i->getType() << " " << std::endl;
	std::cout << "[i->makeSound()]" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "[j->makeSound()]" << std::endl;
	j->makeSound();
	std::cout << "[meta->makeSound()]" << std::endl;
	meta->makeSound();

	std::cout << "[delete meta]" << std::endl;
	delete meta;
	std::cout << "[delete j]" << std::endl;
	delete j;
	std::cout << "[delete i]" << std::endl;
	delete i;
	std::cout << "[delete b]" << std::endl;
	delete b;
	std::cout << "[delete c]" << std::endl;
	delete c;
	std::cout << "[delete p]" << std::endl;
	delete p;
	return 0;
}
