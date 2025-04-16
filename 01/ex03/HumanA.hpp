/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:24:05 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:42:01 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	private:
		std::string name;
		Weapon& weapon;
		std::string& getWeaponType();
	public:
		HumanA(std::string name, Weapon& type);
		void attack();
};

#endif
