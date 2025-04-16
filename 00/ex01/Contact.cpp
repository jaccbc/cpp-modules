/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:05:48 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:58:22 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::clear() {
	memset(firstName, 0, BUFFER_SIZE);
	memset(lastName, 0, BUFFER_SIZE);
	memset(nickname, 0, BUFFER_SIZE);
	memset(phoneNumber, 0, BUFFER_SIZE);
	memset(darkestSecret, 0, BUFFER_SIZE);
}

Contact::Contact() {
	Contact::clear();
}

bool	Contact::isClear() {
	if (firstName[0] || lastName[0] || nickname[0]
		|| phoneNumber[0] || darkestSecret[0]) return (false);
	return (true);
}

size_t	Contact::maxSize() {
	return BUFFER_SIZE ? BUFFER_SIZE - 1 : BUFFER_SIZE;
}

bool	Contact::validPhoneNumber(std::string& userInput) {
	for (std::string::const_iterator i = userInput.begin(); i != userInput.end(); i++)
		if (!std::isdigit(static_cast<unsigned char>(*i)))
			return false;
	return true;
}

bool	Contact::validInput(std::string& userInput) {
	for (std::string::const_iterator i = userInput.begin(); i != userInput.end(); i++)
		if (static_cast<unsigned char>(*i) > 127)
			return false;
	return true;
}

bool	Contact::getInput(const char *prompt, std::string& userInput, char *info, bool phone) {
	while (std::cout << prompt)
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
		if (userInput.size() >= maxSize())
		{
			std::cout << "Only " << maxSize() << " characters allowed!" << std::endl;
			continue ;
		}
		if (phone && validPhoneNumber(userInput) == false)
		{
			std::cout << "Only numbers allowed!" << std::endl;
			continue ;
		}
		if (validInput(userInput) == false)
		{
			std::cout << "Invalid character!" << std::endl;
			continue ;
		}
		return userInput.copy(info, userInput.size());
	}
	return false;
}

bool	Contact::createContact() {
	std::string userInput;

	if (!getInput("first name: ", userInput, firstName, 0)
		|| !getInput("last name: ", userInput, lastName, 0)
		|| !getInput("nickname: ", userInput, nickname, 0)
		|| !getInput("phone number: ", userInput, phoneNumber, 1)
		|| !getInput("darkest secreat: ", userInput, darkestSecret, 0)) return false;
	return true;
}

std::string	Contact::truncate(std::string& str) {
	return str.size() >= 10 ? str.substr(0, 9) + '.' : std::string(10 - str.size(), ' ') + str;
}

void	Contact::printContact() {
	std::string str;
	std::cout << std::right << truncate(str.assign(firstName)) << "|";
	std::cout << std::right << truncate(str.assign(lastName)) << "|";
	std::cout << std::right << truncate(str.assign(nickname)) << "|" << std::endl;
}

void	Contact::printContactAll() {
	std::cout << "first name: " << firstName << std::endl;
	std::cout << "last name: " << lastName << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phoneNumber << std::endl;
	std::cout << "darkest secret: " << darkestSecret << std::endl;
}
