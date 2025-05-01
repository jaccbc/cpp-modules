/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:02:36 by joandre-          #+#    #+#             */
/*   Updated: 2025/05/01 18:14:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie* n;
	try {
		n = new Zombie(name);
		return n;
	}
	catch (const std::bad_alloc& error) {
		std::cout << "newZombie() failure : " << error.what();
		std::cout << std::endl;
		return NULL;
	}
}
