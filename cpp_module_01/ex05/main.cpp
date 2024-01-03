#include "Harl.hpp"

int main() {
    Harl harl;
    std::string level;
    do {
        std::cout << "Enter Level : ";
        std::cin >> level;
        harl.complain(level);
    } while (level != "exit");
}
