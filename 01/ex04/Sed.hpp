/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:27:40 by joandre-          #+#    #+#             */
/*   Updated: 2025/01/21 21:53:43 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

#include <iostream>
#include <fstream>

class Sed
{
	private:
		std::string outFilename;
		std::ifstream infile;
		std::ofstream outfile;
		bool state;
	public:
		Sed(std::string);
		~Sed();
		bool getState() const;
		void replace(const std::string, const std::string);
};

#endif
