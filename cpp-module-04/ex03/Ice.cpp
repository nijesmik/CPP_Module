//
// Created by 김세진 on 5/12/24.
//

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &ice) : AMateria(ice) {}

Ice &Ice::operator=(const Ice &that) {
    if (this != &that) {
        this->type = that.type;
    }
    return *this;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
