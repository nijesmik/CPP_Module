//
// Created by Sejin Kim on 6/28/24.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0) {
    for (int i = 0; i < MAX_MATERIA; i++) {
        materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (materias[i] != NULL) {
            delete materias[i];
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    count = materiaSource.count;
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (materias[i] != NULL) {
            delete materias[i];
        }
        materias[i] = NULL;
        if (materiaSource.materias[i] != NULL) {
            materias[i] = materiaSource.materias[i]->clone();
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this == &materiaSource) {
        return *this;
    }

    count = materiaSource.count;
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (materias[i] != NULL) {
            delete materias[i];
        }
        materias[i] = NULL;
        if (materiaSource.materias[i] != NULL) {
            materias[i] = materiaSource.materias[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (count == MAX_MATERIA) {
        std::cout << "MateriaSource is full!" << std::endl;
        delete materia;
        return;
    }
    materias[count++] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (materias[i] != NULL && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    std::cout << type << " is not found!" << std::endl;
    return NULL;
}
