/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:44:50 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/15 01:24:51 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n = 0) : num(n << BITS) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n = 0) : num(roundf(n * (1 << BITS))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : num(other.num) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		num = other.num;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
}

float	Fixed::toFloat(void) const {
	return (float)num / (1 << BITS);
}

int	Fixed::toInt(void) const {
	return num >> BITS;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& n) {
	return out << n.toFloat();
}
