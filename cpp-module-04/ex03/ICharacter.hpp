//
// Created by 김세진 on 5/12/24.
//

#ifndef CPP_MODULE_ICHARACTER_HPP
#define CPP_MODULE_ICHARACTER_HPP

#include <iostream>

class AMateria;

class ICharacter {
public:
    virtual ~ICharacter() {}

    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

#endif //CPP_MODULE_ICHARACTER_HPP
