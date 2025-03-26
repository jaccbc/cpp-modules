/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:34:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/12/30 00:25:54 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <sstream>

class PhoneBook
{
	private:
		bool indexValid(std::string& str);
		static const size_t MAX_CONTACTS = 8;
		size_t getSlot();
		Contact user[MAX_CONTACTS];
	public:
		bool addContact();
		bool searchContact();
};

#endif
