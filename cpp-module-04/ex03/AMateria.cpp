//
// Created by 김세진 on 5/12/24.
//

#include "AMateria.hpp"

AMateria::AMateria() : type("Materia") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &aMateria) : type(aMateria.type) {}

AMateria &AMateria::operator=(const AMateria &that) {
    if (this != &that) {
        this->type = that.type;
    }
    return *this;
}

std::string const &AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
