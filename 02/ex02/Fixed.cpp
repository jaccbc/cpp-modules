/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:44:50 by joandre-          #+#    #+#             */
/*   Updated: 2025/04/16 11:21:29 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : num(n << BITS) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : num(roundf(n * (1 << BITS))) {
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

bool	Fixed::operator>(const Fixed& other) const {
	return num > other.num;
}

bool	Fixed::operator<(const Fixed& other) const {
	return num < other.num;
}

bool	Fixed::operator>=(const Fixed& other) const {
	return num >= other.num;
}

bool	Fixed::operator<=(const Fixed& other) const {
	return num <= other.num;
}

bool	Fixed::operator==(const Fixed& other) const {
	return num == other.num;
}

bool	Fixed::operator!=(const Fixed& other) const {
	return num != other.num;
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(num + other.num);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(num - other.num);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((num * other.num) >> BITS);
	return !other.num ? other : result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed result;
	if (!num || !other.num) return result;
	result.setRawBits((num << BITS) / other.num);
	return result;
}

Fixed&	Fixed::operator++() {
	num += 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed result(*this);
	num += 1;
	return result;
}

Fixed&	Fixed::operator--() {
	num -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed result(*this);
	num -= 1;
	return result;
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

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& n) {
	return out << n.toFloat();
}
