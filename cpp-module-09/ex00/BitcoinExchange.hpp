//
// Created by 김세진 on 7/10/24.
//

#ifndef CPP_MODULE_BITCOINEXCHANGE_HPP
#define CPP_MODULE_BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include "Date.hpp"

#define DATA_DELIMITER ','
#define INPUT_DELIMITER_EDGE ' '
#define INPUT_DELIMITER_MID "|"

class BitcoinExchange {
private:
    std::map<Date, double> database;

    BitcoinExchange();

    void parseLine(std::string const &line);
    double parseDouble(std::string const &number);
    double parseRate(std::string const &rate);
    double parseValue(std::string const &value);
    void validateDelimiter(std::string const &delimiter);

public:
    BitcoinExchange(const std::string &csvFile);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void calculate(std::string const &inputFile);
    void displayResult(Date const &date, double const &value);
};

#endif //CPP_MODULE_BITCOINEXCHANGE_HPP
