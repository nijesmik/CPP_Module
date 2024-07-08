//
// Created by Sejin Kim on 7/8/24.
//

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input) {
    Printer printer;
    if (input == "nan" || input == "nanf") {
        return printer.printNan();
    }
    if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff") {
        return printer.printInf();
    }
    if (input == "-inf" || input == "-inff") {
        return printer.printMinusInf();
    }

    char *end;
    double value = strtod(input.c_str(), &end);
    if (*end == '\0') {
        printer.printChar(value);
        printer.printInt(value);
        printer.printFloat(value);
        printer.printDouble(value);
    } else {
        std::cerr << "Error: Invalid input" << std::endl;
    }
}
