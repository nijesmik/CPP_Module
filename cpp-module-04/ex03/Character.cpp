//
// Created by 김세진 on 5/12/24.
//

#include "Character.hpp"

Character::Character()
        : name("Character"),
          trashCan(new AMateria *[INVENTORY_SIZE]),
          trashCanSize(INVENTORY_SIZE),
          trashCanIdx(0) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        inventory[i] = NULL;
        trashCan[i] = NULL;
    }
}

Character::Character(std::string const &name)
        : name(name),
          trashCan(new AMateria *[INVENTORY_SIZE]),
          trashCanSize(INVENTORY_SIZE),
          trashCanIdx(0) {

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        inventory[i] = NULL;
        trashCan[i] = NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] != NULL) {
            delete inventory[i];
        }
    }
    for (int i = 0; i < trashCanIdx; i++) {
        delete trashCan[i];
    }
    delete[] trashCan;
}

Character::Character(const Character &character)
        : name(character.name),
          trashCan(new AMateria *[INVENTORY_SIZE]),
          trashCanSize(INVENTORY_SIZE),
          trashCanIdx(0) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] != NULL) {
            delete inventory[i];
        }
        inventory[i] = NULL;
        trashCan[i] = NULL;
        if (character.inventory[i] != NULL) {
            inventory[i] = character.inventory[i]->clone();
        }
    }
}

Character &Character::operator=(const Character &character) {
    if (this == &character) {
        return *this;
    }

    name = character.name;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] != NULL) {
            delete inventory[i];
        }
        inventory[i] = NULL;
        if (character.inventory[i] != NULL) {
            inventory[i] = character.inventory[i]->clone();
        }
    }
    return *this;
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full!" << std::endl;
}

bool Character::isIndexValid(int idx) const {
    if (idx < 0 || idx >= INVENTORY_SIZE) {
        std::cout << "Invalid index!" << std::endl;
        return false;
    }
    return true;
}

bool Character::isInventoryEmpty(int idx) const {
    if (inventory[idx] == NULL) {
        std::cout << "Empty slot!" << std::endl;
        return true;
    }
    return false;
}

void Character::deleteMateria(AMateria *materia) {
    if (trashCanIdx == trashCanSize) {
        trashCanSize = trashCanSize * 2;
        AMateria **newTrashCan = new AMateria *[trashCanSize];
        for (int i = 0; i < trashCanIdx; i++) {
            newTrashCan[i] = trashCan[i];
        }
        delete[] trashCan;
        trashCan = newTrashCan;
    }
    trashCan[trashCanIdx++] = materia;
}

void Character::unequip(int idx) {
    if (isIndexValid(idx) && !isInventoryEmpty(idx)) {
        deleteMateria(inventory[idx]);
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (isIndexValid(idx) && !isInventoryEmpty(idx)) {
        inventory[idx]->use(target);
    }
}
