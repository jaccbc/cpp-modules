/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:02:36 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:37:19 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) return NULL;
	try
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			std::stringstream ss;
			ss << name << "_" << i;
			horde[i].setName(ss.str());
		}
		return horde;
	}
	catch (const std::bad_alloc& error)
	{
		std::cout << error.what() << std::endl;
		return NULL;
	}
}
