/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:24:05 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/26 21:26:04 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string);
		void setWeapon(Weapon&);
		void attack();

};

#endif
