//
// Created by 김세진 on 5/12/24.
//

#ifndef CPP_MODULE_CHARACTER_HPP
#define CPP_MODULE_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter {
private:
    std::string name;
    AMateria *inventory[INVENTORY_SIZE];
    AMateria **trashCan;
    int trashCanSize;
    int trashCanIdx;

    bool isIndexValid(int idx) const;
    bool isInventoryEmpty(int idx) const;
    void deleteMateria(AMateria *materia);

public:
    Character();
    Character(std::string const &name);
    ~Character();
    Character(const Character &character);
    Character &operator=(const Character &character);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif //CPP_MODULE_CHARACTER_HPP
