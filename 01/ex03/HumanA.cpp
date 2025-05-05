/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:16:22 by joandre-          #+#    #+#             */
/*   Updated: 2025/05/05 13:29:23 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& type) : name(str), weapon(type) {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType();
	std::cout << std::endl;
}
