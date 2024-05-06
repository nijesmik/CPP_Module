//
// Created by 김세진 on 4/28/24.
//

#include "ScavTrap.hpp"

int main() {
    ScavTrap trap1("trap1");
    ClapTrap trap2("trap2");
    std::cout << std::endl;

//    trap1.realAttack(trap2);
//    std::cout << std::endl;
//
//    trap2.realAttack(trap1);
//    std::cout << std::endl;

    ClapTrap *trap1Ptr = &trap1;
    trap1Ptr->attack("trap2");
    std::cout << std::endl;

    return 0;
}