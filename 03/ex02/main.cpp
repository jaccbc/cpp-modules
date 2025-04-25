/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:22:26 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/25 18:50:29 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a;
	FragTrap b("Android");
	FragTrap c(FragTrap("Slime"));
	c = FragTrap("Crazy");

	a.attack("minions");
	b.takeDamage(22);
	c.beRepaired(1);
	b.attack("monster");
	b.takeDamage(420);
	b.beRepaired(10);
	for (int i = 0; i < 54; i++) a.attack("minions");
	b.attack("Ghost");
	c.highFivesGuys();
	return 0;
}
