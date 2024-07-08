//
// Created by Sejin Kim on 7/8/24.
//

#ifndef CPP_MODULE_SCALARCONVERTER_HPP
#define CPP_MODULE_SCALARCONVERTER_HPP

#include <iostream>
#include "Printer.hpp"

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &scalarConverter);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &scalarConverter);

public:
    static void convert(const std::string &input);
};

#endif //CPP_MODULE_SCALARCONVERTER_HPP
