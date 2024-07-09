//
// Created by 김세진 on 7/8/24.
//

#include "iter.hpp"
#include <iostream>

#define LENGTH 5

template<typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

int increment(int &x) {
    return ++x;
}

int main() {
    int arr[LENGTH] = {1, 2, 3, 4, 5};
    std::string arr2[LENGTH] = {"one", "two", "three", "four", "five"};

    iter(arr, LENGTH, increment);
    iter(arr, LENGTH, print<int>);

    iter(arr2, LENGTH, print<std::string>);

    return 0;
}
