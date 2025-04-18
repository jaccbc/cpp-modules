/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:21:25 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:40:29 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : name(str), weapon(NULL) {}

void HumanB::setWeapon(Weapon& type) {
	weapon = &type;
}

void HumanB::attack() {
	weapon ? std::cout << name << " attacks with their " << weapon->getType() << std::endl
		: std::cout << name << " attacks with their bare hands" << std::endl;
}
