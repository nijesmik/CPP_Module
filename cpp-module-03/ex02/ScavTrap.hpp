//
// Created by 김세진 on 5/5/24.
//

#ifndef CPP_MODULE_SCAVTRAP_HPP
#define CPP_MODULE_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();

    ScavTrap(std::string name);

    ScavTrap(const ScavTrap &scavTrap);

    ScavTrap &operator=(const ScavTrap &scavTrap);

    ~ScavTrap();

    void attack(std::string const &target);

    void guardGate();
};

#endif //CPP_MODULE_SCAVTRAP_HPP
