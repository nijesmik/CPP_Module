//
// Created by 김세진 on 5/12/24.
//

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &cure) : AMateria(cure) {}

Cure &Cure::operator=(const Cure &that) {
    if (this != &that) {
        this->type = that.type;
    }
    return *this;
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}