//
// Created by Sejin Kim on 6/28/24.
//

#ifndef CPP_MODULE_IMATERIASOURCE_HPP
#define CPP_MODULE_IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif //CPP_MODULE_IMATERIASOURCE_HPP
