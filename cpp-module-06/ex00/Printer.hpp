//
// Created by Sejin Kim on 7/8/24.
//

#ifndef CPP_MODULE_PRINTER_HPP
#define CPP_MODULE_PRINTER_HPP

#include <iostream>
#include <cctype>
#include <limits>

class Printer {
public:
    void printChar(double input);
    void printInt(double input);
    void printFloat(double input);
    void printDouble(double input);
    void printImpossible(std::string type);
    void printNan();
    void printInf();
    void printMinusInf();

private:
    void printInff();
    void printMinusInff();
};

#endif //CPP_MODULE_PRINTER_HPP
