//
// Created by 김세진 on 5/11/24.
//

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "🐶 Hello!" << std::endl;
}

Dog::~Dog() {
    std::cout << "🐶 Bye~!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "🐶 Hello! I'm a clone." << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog) {
        type = dog.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐶 Woof~" << std::endl;
}

