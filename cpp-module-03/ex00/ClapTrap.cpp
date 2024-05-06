//
// Created by 김세진 on 4/28/24.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap \"" << name << "\" is created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap \"" << name << "\" is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;
    std::cout << "ClapTrap \"" << name << "\" is cloned!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    if (this == &clapTrap) {
        return *this;
    }
    name = clapTrap.name;
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap \"" << name << "\" is destroyed!" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap \"" << name << "\" is dead. it can't attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap \"" << name << "\" is out of energy. it can't attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap \"" << name << "\" attacks \"" << target << "\", causing " << attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::attack(ClapTrap &target) {
    if (this == &target) {
        std::cout << "ClapTrap \"" << name << "\" can't attack itself!" << std::endl;
        return;
    }
    attack(target.name);
    target.takeDamage(attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap \"" << name << "\" is already dead. it can't take damage!" << std::endl;
        return;
    }
    hitPoints -= amount;
    std::cout << "ClapTrap \"" << name << "\" takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap \"" << name << "\" is dead. it can't be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap \"" << name << "\" is out of energy. it can't be repaired!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap \"" << name << "\" is repaired for " << amount << " points!" << std::endl;
}
