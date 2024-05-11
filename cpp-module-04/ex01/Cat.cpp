//
// Created by 김세진 on 5/11/24.
//

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
    std::cout << "🐱 Hello!" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "🐱 Bye~!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), brain(new Brain(*cat.brain)) {
    std::cout << "🐱 Hello! I'm a clone." << std::endl;
}

Cat &Cat::operator=(const Cat &that) {
    if (this != &that) {
        this->type = that.type;
        *this->brain = *that.brain;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "🐱 Meow~" << std::endl;
}

Brain *Cat::getBrain() const {
    return brain;
}
