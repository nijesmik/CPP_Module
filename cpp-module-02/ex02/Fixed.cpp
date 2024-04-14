//
// Created by 김세진 on 4/11/24.
//

#include "Fixed.hpp"

Fixed::Fixed() : rawBit(0) {}

Fixed::Fixed(const int value) : rawBit(value << this->fractionalBits) {}

Fixed::Fixed(const float value) : rawBit(roundf(value * (1 << this->fractionalBits))) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    this->rawBit = fixed.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    if (fixed.toFloat() == 0) {
        std::cout << "Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / fixed.toFloat());
}

bool Fixed::operator>(const Fixed &fixed) const {
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) const {
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) const {
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return this->toFloat() != fixed.toFloat();
}

Fixed &Fixed::operator++() {
    this->rawBit++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    this->rawBit--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
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
