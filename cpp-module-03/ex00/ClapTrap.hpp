//
// Created by 김세진 on 4/28/24.
//

#ifndef CPP_MODULE_CLAPTRAP_HPP
#define CPP_MODULE_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap();

    ClapTrap(std::string name);

    ClapTrap(const ClapTrap &clapTrap);

    ClapTrap &operator=(const ClapTrap &clapTrap);

    ~ClapTrap();

    void attack(std::string const &target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

//    std::string getName() const;
//
//    void realAttack(ClapTrap &target);

};

#endif //CPP_MODULE_CLAPTRAP_HPP
