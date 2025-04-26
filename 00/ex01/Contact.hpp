/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:59:18 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/26 01:00:54 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>

class Contact {
	private:
		bool getInput(const char *prompt, std::string& userInput, char *info, bool phone);
		bool validInput(std::string& userInput);
		bool validPhoneNumber(std::string& userInput);
		std::string truncate(std::string& str);
		static const size_t BUFFER_SIZE = 20;
		char firstName[BUFFER_SIZE];
		char lastName[BUFFER_SIZE];
		char nickname[BUFFER_SIZE];
		char phoneNumber[BUFFER_SIZE];
		char darkestSecret[BUFFER_SIZE];
	public:
		Contact();
		bool createContact();
		void printContact();
		void printContactAll();
		size_t maxSize();
		bool isClear();
		void clear();
};

#endif
