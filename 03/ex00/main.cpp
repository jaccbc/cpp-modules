/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:22:26 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/18 21:11:13 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	ClapTrap b("Android");
	ClapTrap c(ClapTrap("Slime"));
	c = b;

	a.attack("minions");
	b.takeDamage(22);
	c.beRepaired(1);
	b.attack("Marvin");
	b.takeDamage(42);
	b.beRepaired(10);
	return 0;
}
