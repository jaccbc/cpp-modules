/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:16:22 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:39:04 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& type) : name(str), weapon(type) {}

std::string& HumanA::getWeaponType() {
	return weapon.getType();
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << getWeaponType() << std::endl;
}
