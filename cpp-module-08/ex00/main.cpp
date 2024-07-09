//
// Created by 김세진 on 7/9/24.
//

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}