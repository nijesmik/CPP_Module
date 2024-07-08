//
// Created by Sejin Kim on 7/8/24.
//

#include "Printer.hpp"

void Printer::printChar(double input) {
    if (input < std::numeric_limits<char>::min() || input > std::numeric_limits<char>::max()) {
        return printImpossible("char");
    }
    char c = static_cast<char>(input);
    if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void Printer::printInt(double input) {
    if (input < std::numeric_limits<int>::min() || input > std::numeric_limits<int>::max()) {
        return printImpossible("int");
    }
    std::cout << "int: " << static_cast<int>(input) << std::endl;
}

void Printer::printFloat(double input) {
    if (input > std::numeric_limits<float>::max()) {
        return printInff();
    }
    if (input < -std::numeric_limits<float>::max()) {
        return printMinusInff();
    }
    std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
}

void Printer::printDouble(double input) {
    std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void Printer::printImpossible(std::string type) {
    std::cout << type << ": impossible" << std::endl;
}

void Printer::printNan() {
    printImpossible("char");
    printImpossible("int");
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void Printer::printInff() {
    std::cout << "float: inff" << std::endl;
}

void Printer::printMinusInff() {
    std::cout << "float: -inff" << std::endl;
}

void Printer::printInf() {
    printImpossible("char");
    printImpossible("int");
    printInff();
    std::cout << "double: inf" << std::endl;
}

void Printer::printMinusInf() {
    printImpossible("char");
    printImpossible("int");
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}
