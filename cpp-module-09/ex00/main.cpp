//
// Created by 김세진 on 7/10/24.
//

#include "BitcoinExchange.hpp"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

#define DATA_BASE "data.csv"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED << "USAGE: ./btc [input_file]" << RESET << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange(DATA_BASE);
        exchange.calculate(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}