/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:09:43 by joandre-          #+#    #+#             */
/*   Updated: 2025/05/05 12:44:25 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HORDE 15

#include "Zombie.hpp"

int	main(void) {
	Zombie* horde = zombieHorde(HORDE, "Tarman");
	if (horde == NULL) return 1;
	for (int i = 0; i < HORDE; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
