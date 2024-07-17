//
// Created by 김세진 on 7/14/24.
//

#include "PmergeMe.hpp"

#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << BLUE << "USAGE: ./PmergeMe [number1] [number2] ... [numberN]" << RESET << std::endl;
        return 1;
    }

    try {
        PmergeMe pmm(argv + 1, argc - 1);
        pmm.sortWithVector();
        std::cout << std::endl;
        pmm.sortWithDeque();
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
