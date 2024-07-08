//
// Created by 김세진 on 7/6/24.
//

#include "Serializer.hpp"
#include <iostream>
#include <sstream>

Data newData(int date, std::string text) {
    Data data;
    data.date = date;
    data.text = text;
    return data;
}

int main() {
    Data data1 = newData(20240624, "Hello, World!");

    uintptr_t serializedData = Serializer::serialize(&data1);
    Data *data2 = Serializer::deserialize(serializedData);

    std::cout << "address of data1: " << &data1 << std::endl;

    std::stringstream ss;
    ss << std::hex << serializedData;
    std::cout << "serialized data: " << serializedData << std::endl;
    std::cout << "serialized data(hex): " << ss.str() << std::endl;

    std::cout << "address of data2: " << data2 << std::endl;

    return 0;
}
