//
// Created by 김세진 on 5/12/24.
//

#ifndef CPP_MODULE_AMATERIA_HPP
#define CPP_MODULE_AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria(const AMateria &aMateria);
    AMateria &operator=(const AMateria &aMateria);

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif //CPP_MODULE_AMATERIA_HPP
