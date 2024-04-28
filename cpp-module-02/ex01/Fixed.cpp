//
// Created by 김세진 on 4/11/24.
//

#include "Fixed.hpp"

Fixed::Fixed() : rawBit(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : rawBit(value << this->fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawBit(roundf(value * (1 << this->fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignation operator called" << std::endl;
    this->rawBit = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return this->rawBit;
}

void Fixed::setRawBits(int const raw) {
    this->rawBit = raw;
}

int Fixed::toInt() const {
    return this->rawBit >> this->fractionalBits;
}

float Fixed::toFloat() const {
    return (float) this->rawBit / (1 << this->fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
