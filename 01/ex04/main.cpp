/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:33:24 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:53:34 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

static bool verifyInput(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return false;
	}
	if (*argv[1]) return true;
	std::cout << "Error: Empty filename" << std::endl;
	return false;
}

int	main(int argc, char **argv) {
	if (verifyInput(argc, argv) == false) return -1;
	Sed file(argv[1]);
	file.replace(argv[2], argv[3]);
	if (file.getState()) return 0;
	return 1;
}
