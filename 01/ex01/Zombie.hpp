/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:44:43 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:37:45 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie(void);
		void announce(void) const;
		void setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
