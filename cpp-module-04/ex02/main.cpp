//
// Created by 김세진 on 5/11/24.
//

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
//    Animal animal;

    int N = 5;
    const Animal *animals[N];

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; i++) {
        delete animals[i];
        std::cout << std::endl;
    }

    return 0;
}
