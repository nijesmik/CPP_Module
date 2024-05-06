//
// Created by 김세진 on 5/5/24.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "🪓 ScavTrap mode for \"" << name << "\" is activated!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "🪓 ScavTrap mode for \"" << name << "\" is activated!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
    *this = scavTrap;
    std::cout << "🪓 ScavTrap \"" << name << "\" is cloned!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    if (this == &scavTrap) {
        return *this;
    }
    name = scavTrap.name;
    hitPoints = scavTrap.hitPoints;
    energyPoints = scavTrap.energyPoints;
    attackDamage = scavTrap.attackDamage;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "🪓 ScavTrap mode for \"" << name << "\" is deactivated!" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
    if (hitPoints == 0) {
        std::cout << "😇 \"" << name << "\" is dead. it can't attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "😭 \"" << name << "\" is out of energy. it can't attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "🧨️\"" << name << "\" attacks \"" << target << "\", causing " << attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    if (hitPoints == 0) {
        std::cout << "😇 \"" << name << "\" is dead. it can't guard the gate!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "😭 \"" << name << "\" is out of energy. it can't guard the gate!" << std::endl;
        return;
    }
    std::cout << "🚪 \"" << name << "\" is now in gate keeper mode!" << std::endl;
}
