//
// Created by 김세진 on 4/28/24.
//

#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap1;
    ClapTrap clapTrap2("clapTrap2");
    ClapTrap clapTrap3(clapTrap2);

    clapTrap3.attack(clapTrap2);
    clapTrap2.attack(clapTrap2);
    return 0;
}