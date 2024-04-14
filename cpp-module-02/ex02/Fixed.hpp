//
// Created by 김세진 on 4/11/24.
//

#ifndef CPP_MODULE_FIXED_HPP
#define CPP_MODULE_FIXED_HPP

#include "iostream"
#include "cmath"

class Fixed {
private:
    int rawBit;
    static const int fractionalBits = 8;

public:
    Fixed();

    Fixed(const int value);

    Fixed(const float value);

    Fixed(const Fixed &fixed);

    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

    Fixed operator+(const Fixed &fixed) const;

    Fixed operator-(const Fixed &fixed) const;

    Fixed operator*(const Fixed &fixed) const;

    Fixed operator/(const Fixed &fixed) const;

    bool operator>(const Fixed &fixed) const;

    bool operator<(const Fixed &fixed) const;

    bool operator>=(const Fixed &fixed) const;

    bool operator<=(const Fixed &fixed) const;

    bool operator==(const Fixed &fixed) const;

    bool operator!=(const Fixed &fixed) const;

    Fixed &operator++();

    Fixed operator++(int);

    Fixed &operator--();

    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);

    static const Fixed &min(const Fixed &a, const Fixed &b);

    static Fixed &max(Fixed &a, Fixed &b);

    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits() const;

    void setRawBits(int const raw);

    int toInt() const;

    float toFloat() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //CPP_MODULE_FIXED_HPP
