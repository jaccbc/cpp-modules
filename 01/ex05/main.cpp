/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:27:38 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:55:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl bot;
	std::string lvl[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;
	while (i < 4)
		bot.complain(lvl[i++]);
	return 0;
}
