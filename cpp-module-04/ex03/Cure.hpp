//
// Created by 김세진 on 5/12/24.
//

#ifndef CPP_MODULE_CURE_HPP
#define CPP_MODULE_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    ~Cure();
    Cure(const Cure &cure);
    Cure &operator=(const Cure &cure);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif //CPP_MODULE_CURE_HPP
