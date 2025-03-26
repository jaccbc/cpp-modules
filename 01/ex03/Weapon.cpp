/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:30:38 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/26 21:37:01 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : type(str) {}

std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string str)
{
	type = str;
}
