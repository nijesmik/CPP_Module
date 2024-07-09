//
// Created by 김세진 on 7/8/24.
//

#ifndef CPP_MODULE_WHATEVER_HPP
#define CPP_MODULE_WHATEVER_HPP

template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T const &a, T const &b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<typename T>
T max(T const &a, T const &b) {
    if (a > b) {
        return a;
    }
    return b;
}

#endif //CPP_MODULE_WHATEVER_HPP
