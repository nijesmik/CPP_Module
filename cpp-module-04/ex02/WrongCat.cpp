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

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
    std::cout << "😈 Hello! I'm a clone." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &that) {
    if (this != &that) {
        this->type = that.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "😈 Meow~" << std::endl;
}
