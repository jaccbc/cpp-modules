/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:03:01 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/02 19:34:50 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int ac = 1; ac != argc; ac++)
		for (int i = 0; argv[ac][i]; i++)
			std::cout << (char)std::toupper(argv[ac][i]);
	std::cout << std::endl;
	return argc == 1 ? 1 : 0;
}
