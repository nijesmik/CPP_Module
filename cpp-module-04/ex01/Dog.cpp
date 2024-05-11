//
// Created by 김세진 on 5/11/24.
//

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "🐶 Hello!" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "🐶 Bye~!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), brain(new Brain(*dog.brain)) {
    std::cout << "🐶 Hello! I'm a clone." << std::endl;
}

Dog &Dog::operator=(const Dog &that) {
    if (this != &that) {
        this->type = that.type;
        *this->brain = *that.brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐶 Woof~" << std::endl;
}

Brain *Dog::getBrain() const {
    return brain;
}
