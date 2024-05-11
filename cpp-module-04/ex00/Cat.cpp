//
// Created by 김세진 on 5/11/24.
//

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "🐱 Hello!" << std::endl;
}

Cat::~Cat() {
    std::cout << "🐱 Bye~!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    std::cout << "🐱 Hello! I'm a clone." << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat) {
        type = cat.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "🐱 Meow~" << std::endl;
}
