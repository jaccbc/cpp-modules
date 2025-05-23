/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:18:24 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:44:57 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string weapon);
		std::string& getType();
		void setType(const std::string weapon);
};

#endif
