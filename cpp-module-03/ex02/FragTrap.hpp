//
// Created by 김세진 on 5/6/24.
//

#ifndef CPP_MODULE_FRAGTRAP_HPP
#define CPP_MODULE_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();

    FragTrap(std::string name);

    FragTrap(const FragTrap &fragTrap);

    FragTrap &operator=(const FragTrap &fragTrap);

    ~FragTrap();

    void highFivesGuys();
};

#endif //CPP_MODULE_FRAGTRAP_HPP
