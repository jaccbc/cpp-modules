/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:02 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/25 19:18:25 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Marvin"), hp(10), energy(10), damage(0) {
	std::cout << "[ClapTrap] " << name << " has spawned! 🐣";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), damage(0) {
	std::cout << "[ClapTrap] " << name << " has been created! 🔧";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hp(other.hp),
	energy(other.energy), damage(other.damage) {
		std::cout << "[ClapTrap] " << name << " has been cloned. 🔑";
		std::cout << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "[ClapTrap] " << name << " has been copied from " << other.name << ". 📷";
	std::cout <<  std::endl;
	if (this != &other) {
		name = other.name;
		hp = other.hp;
		energy = other.energy;
		damage = other.damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] " << name << " self-destructs! 💥";
	std::cout << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "[ClapTrap] " << name;
	if (!hp || !energy) {
		std::cout << " has no ";
		!hp ? std::cout << "hit points" : std::cout << "energy";
		std::cout << " left to attack. 🔋" << std::endl;
		return ;
	}
	--energy;
	std::cout<< " attacks " << target << ", causing " << damage << " points of damage! 🗡️";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "[ClapTrap] " << name; 
	if (!hp) {
		std::cout << " has no hit points left. 💀";
		std::cout << std::endl;
		return ;
	}
	(amount > hp) ? hp = 0 : hp -= amount;
	std::cout << " was attacked, loosing " << amount << " hit points. 🔥";
	std::cout << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount) {
	hp += amount;
	std::cout << "[ClapTrap] " << name << " is being repaired. ";
	std::cout << "It gets " << amount << " hit points back. ❤️";
	std::cout << std::endl;
}
