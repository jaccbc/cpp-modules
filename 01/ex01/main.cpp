/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:09:43 by joandre-          #+#    #+#             */
/*   Updated: 2025/01/04 02:06:16 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HORDE 15

#include "Zombie.hpp"

int	main(void)
{
	int N = HORDE;
	Zombie* horde = zombieHorde(N, "Tarman");
	if (horde == NULL)
		return 1;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
