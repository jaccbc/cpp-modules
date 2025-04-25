/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/25 19:24:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hp = 100;
	energy = 50;
	damage = 20;
	std::cout << "[ScavTrap] " << name << " was built! 👷";
	std::cout << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hp = 100;
	energy = 50;
	damage = 20;
	std::cout << "[ScavTrap] " << name << " was created! ⚙️";
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	hp = 100;
	energy = 50;
	damage = 20;
	std::cout << "[ScavTrap] " << name << " was cloned. ⛓️";
	std::cout << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "[ScavTrap] " << name << " was copied from " << other.name << ". 📝";
	std::cout <<  std::endl;
	if (this != &other) {
		name = other.name;
		hp = other.hp;
		energy = other.energy;
		damage = other.damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] " << name << " shuts down! 💤";
	std::cout << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "[ScavTrap] " << name;
	if (!hp || !energy) {
		std::cout << " don't have ";
		!hp ? std::cout << "hit points" : std::cout << "energy";
		std::cout << " left to attack. 🚫" << std::endl;
		return ;
	}
	--energy;
	std::cout << " attacks " << target;
	std::cout << ", causing " << damage << " points of damage! 🏹";
	std::cout << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "[ScavTrap] " << name << " is now in Gate keeper mode. 🛡️";
	std::cout << std::endl;
}
