//
// Created by 김세진 on 5/11/24.
//

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "😈 Hello!" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "😈 Bye~!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat) {
    std::cout << "😈 Hello! I'm a clone." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
    if (this != &cat) {
        type = cat.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "😈 Meow~" << std::endl;
}
