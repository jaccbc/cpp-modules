/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:22:26 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/20 01:16:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a;
	ScavTrap b("Android");
	ScavTrap c(ScavTrap("Slime"));
	c = ScavTrap("Crazy");

	a.attack("minions");
	b.takeDamage(22);
	c.beRepaired(1);
	b.attack("monster");
	b.takeDamage(420);
	b.beRepaired(10);
	for (int i = 0; i < 54; i++) a.attack("minions");
	c.guardGate();
	b.attack("Ghost");
	return 0;
}
