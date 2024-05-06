//
// Created by 김세진 on 5/6/24.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "🪚 FragTrap mode for \"" << name << "\" is activated!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "🪚 FragTrap mode for \"" << name << "\" is activated!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
    *this = fragTrap;
    std::cout << "🪚 FragTrap \"" << name << "\" is cloned!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    if (this == &fragTrap) {
        return *this;
    }
    name = fragTrap.name;
    hitPoints = fragTrap.hitPoints;
    energyPoints = fragTrap.energyPoints;
    attackDamage = fragTrap.attackDamage;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "🪚 FragTrap mode for \"" << name << "\" is deactivated!" << std::endl;
}

void FragTrap::highFivesGuys() {
    if (hitPoints == 0) {
        std::cout << "😇 \"" << name << "\" is dead. it can't high five!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "😭 \"" << name << "\" is out of energy. it can't high five!" << std::endl;
        return;
    }
    std::cout << "👋 \"" << name << "\" wants to high five!" << std::endl;
}
