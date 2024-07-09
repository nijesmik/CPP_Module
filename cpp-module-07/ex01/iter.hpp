//
// Created by 김세진 on 7/8/24.
//

#ifndef CPP_MODULE_ITER_HPP
#define CPP_MODULE_ITER_HPP

#include <cstddef>

template<typename T, typename F>
void iter(T *array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif //CPP_MODULE_ITER_HPP
