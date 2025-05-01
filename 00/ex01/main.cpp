/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:14:18 by joandre-          #+#    #+#             */
/*   Updated: 2025/05/01 18:03:17 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define PROMPT "myPhoneBook$ "

int	main(void) {
	std::string userInput;
	PhoneBook root;

	std::cout << "My Awesome PhoneBook only accepts ADD, SEARCH and EXIT" << std::endl;
	while (std::cout << PROMPT)
	{
		if (std::getline(std::cin, userInput) == false)
		{
			if (std::cin.eof() && std::cin.fail())
			{
				clearerr(stdin);
				std::cin.clear();
				std::cout << std::endl;
				continue ;
			}
			break ;
		}
		if (userInput.compare("ADD") == 0 && root.addContact() == false)
			break ;
		else if (userInput.compare("SEARCH") == 0 && root.searchContact() == false)
				break ;
		else if (userInput.compare("EXIT") == 0)
			return std::cout << "The contacts are lost forever!" << std::endl, 0;
	}
	return std::cout << "I/O stream failure!" << std::endl, 1;
}
