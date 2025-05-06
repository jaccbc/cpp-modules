/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:15:00 by joandre-          #+#    #+#             */
/*   Updated: 2025/05/06 14:24:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : outFilename(filename + ".replace") {
	state = true;
	infile.open(filename.c_str());
	if (infile.is_open() == false)
	{
		std::cout << "Error: Could not open " << filename << std::endl;
		state = false;
	}
	outfile.open(outFilename.c_str());
	if (outfile.is_open() == false)
	{
		std::cout << "Error: Could not open " << outFilename << std::endl;
		state = false;
	}
}

Sed::~Sed() {
	if (infile.is_open())
		infile.close();
	if (outfile.is_open())
		outfile.close();
	if (getState() == false)
		remove(outFilename.c_str());
}

bool	Sed::getState() const {
	return state;
}

void	Sed::replace(const std::string& s1, const std::string& s2) {
	if (state == false) return ;
	std::string content;
	if (!std::getline(infile, content, '\0'))
	{
		std::cout << "Error: Failure reading file" << std::endl;
		state = false;
		return ;
	}
	if (!s1.empty())
	{
		size_t	i = content.find(s1);
		while (i != content.npos)
		{
			content.erase(i, s1.length());
			content.insert(i, s2);
			i = content.find(s1);
		}
	}
	outfile << content;
}
