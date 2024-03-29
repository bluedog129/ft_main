/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choihyojong <choihyojong@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:55:58 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/23 23:02:02 by choihyojong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(0) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _value(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return (toFloat());
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}