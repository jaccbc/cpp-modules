/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/25 19:34:47 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hp = 100;
	energy = 100;
	damage = 30;
	std::cout << "[FragTrap] " << name << " has emerged! 🤖";
	std::cout << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hp = 100;
	energy = 100;
	damage = 30;
	std::cout << "[FragTrap] " << name << " has booted up! 💡";
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	hp = 100;
	energy = 100;
	damage = 30;
	std::cout << "[FragTrap] " << name << " has been cloned. 👤";
	std::cout << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "[FragTrap] " << name << " has been copied from " << other.name << ". 🔍";
	std::cout <<  std::endl;
	if (this != &other) {
		name = other.name;
		hp = other.hp;
		energy = other.energy;
		damage = other.damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << name << " stalled! 🛑";
	std::cout << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout << "[FragTrap] " << name;
	if (!hp || !energy) {
		std::cout << " don't have ";
		!hp ? std::cout << "hit points" : std::cout << "energy";
		std::cout << " left to attack. ⚡" << std::endl;
		return ;
	}
	--energy;
	std::cout << " attacks " << target;
	std::cout << ", causing " << damage << " points of damage! 🔫";
	std::cout << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] " << name << " gives high five! ✋";
	std::cout << std::endl;
}
