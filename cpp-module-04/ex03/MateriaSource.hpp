//
// Created by Sejin Kim on 6/28/24.
//

#ifndef CPP_MODULE_MATERIASOURCE_HPP
#define CPP_MODULE_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource {
private:
    AMateria *materias[MAX_MATERIA];
    int count;

public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &materiaSource);
    MateriaSource &operator=(const MateriaSource &materiaSource);

    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);
};

#endif //CPP_MODULE_MATERIASOURCE_HPP
