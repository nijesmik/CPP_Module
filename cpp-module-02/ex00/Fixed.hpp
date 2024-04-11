//
// Created by 김세진 on 4/11/24.
//

#ifndef CPP_MODULE_FIXED_HPP
#define CPP_MODULE_FIXED_HPP

#include "iostream"

class Fixed {
private:
    int rawBit;
    static const int fractionalBits = 8;

public:
    Fixed();

    Fixed(const Fixed &fixed);

    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

    int getRawBits() const;

    void setRawBits(int const raw);
};

#endif //CPP_MODULE_FIXED_HPP
