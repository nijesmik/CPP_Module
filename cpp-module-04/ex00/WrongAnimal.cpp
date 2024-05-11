//
// Created by 김세진 on 5/11/24.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "🚫 A wrong animal of type '" << this->type << "' has appeared." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "🚫 A wrong animal of type '" << this->type << "' has appeared." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "🚫 A wrong animal of type '" << type << "' has disappeared." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
    *this = animal;
    std::cout << "🚫 A wrong animal of type '" << this->type << "' has been cloned." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
    if (this != &animal) {
        type = animal.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "🚫 ~~" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
