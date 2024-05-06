//
// Created by 김세진 on 4/28/24.
//

#include "ClapTrap.hpp"

int main() {
    ClapTrap trap1("trap1");
    ClapTrap trap2("trap2");

//    trap1.realAttack(trap2);

    trap2.takeDamage(100);
//    trap1.realAttack(trap2);

    for (int i = 0; i < 10; i++) {
        trap1.beRepaired(1);
    }

//    trap1.realAttack(trap2);

    return 0;
}