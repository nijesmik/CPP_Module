//
// Created by 김세진 on 5/12/24.
//

#ifndef CPP_MODULE_ICE_HPP
#define CPP_MODULE_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    ~Ice();
    Ice(const Ice &ice);
    Ice &operator=(const Ice &ice);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif //CPP_MODULE_ICE_HPP
