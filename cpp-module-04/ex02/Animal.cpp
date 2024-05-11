//
// Created by 김세진 on 5/11/24.
//

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "🥚 An animal of type '" << this->type << "' has appeared." << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "🥚 An animal of type '" << this->type << "' has appeared." << std::endl;
}

Animal::~Animal() {
    std::cout << "🥚 An animal of type '" << type << "' has disappeared." << std::endl;
}

Animal::Animal(const Animal &animal) {
    *this = animal;
    std::cout << "🥚 An animal of type '" << this->type << "' has been cloned." << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal) {
        type = animal.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return type;
}
