/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:09:43 by joandre-          #+#    #+#             */
/*   Updated: 2025/01/04 01:43:58 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *heapZombie = newZombie("Heap");
	if (heapZombie == NULL)
		return 1;
	heapZombie->announce();
	delete heapZombie;
	randomChump("Stack");
	return 0;
}
