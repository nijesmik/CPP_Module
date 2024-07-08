//
// Created by 김세진 on 7/6/24.
//

#ifndef CPP_MODULE_SERIALIZER_HPP
#define CPP_MODULE_SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &serializer);
    Serializer &operator=(const Serializer &serializer);

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif //CPP_MODULE_SERIALIZER_HPP
