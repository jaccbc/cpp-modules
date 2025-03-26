/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:24:05 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/26 21:35:09 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
		std::string& getWeaponType();
	public:
		HumanA(std::string, Weapon&);
		void attack();
};

#endif
