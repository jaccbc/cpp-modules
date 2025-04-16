/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:11:54 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:59:34 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

size_t	PhoneBook::getSlot() {
	size_t	i = 0;
	while (!user[i].isClear() && i < MAX_CONTACTS - 1)
		++i;
	return i;
}

bool	PhoneBook::addContact() {
	size_t i = getSlot();
	if (i == MAX_CONTACTS - 1)
		user[i].clear();
	std::cout << "<< NEW PHONEBOOK CONTACT >>" << std::endl;
	return user[i].createContact();
}

bool	PhoneBook::indexValid(std::string& str) {
	for (std::string::const_iterator i = str.begin(); i != str.end(); i++)
		if (!std::isdigit(static_cast<unsigned char>(*i))) return false;
	return true;
}

bool	PhoneBook::searchContact()
{
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	for (size_t i = 0; i < MAX_CONTACTS; i++)
	{
		if (user[i].isClear())
			break ;
		std::cout << std::setw(10) << std::right << i << "|";
		user[i].printContact();
	}
	std::string userInput;
	while (std::cout << "index: ")
	{
		std::getline(std::cin, userInput);
		if (std::cin.eof() && std::cin.fail())
		{
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			continue ;
		}
		if (userInput.empty())
			continue ;
		if (std::cin.good())
		{
			std::stringstream ss(userInput);
			int i = 0;
			ss >> i;
			if (indexValid(userInput) == false
				|| i < 0 || i > 7 || user[i].isClear())
			{
				std::cout << "Invalid index!" << std::endl;
				continue;
			}
			user[i].printContactAll();
			return true;
		}
		break ;
	}
	return false;
}
