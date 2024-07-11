//
// Created by 김세진 on 7/10/24.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &csvFile) {
    std::ifstream file(csvFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "date,exchange_rate") {
            continue;
        }
        std::stringstream ss(line);
        // date
        std::string date;
        std::getline(ss, date, DATA_DELIMITER);
        Date d(date);
        // exchange rate
        std::string rate;
        std::getline(ss, rate);
        double r = parseRate(rate);
        database.insert(std::make_pair(d, r));
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other) {
        return *this;
    }
    database = other.database;
    return *this;
}

void BitcoinExchange::calculate(const std::string &inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "date | value") {
            continue;
        }
        parseLine(line);
    }
    file.close();
}

void BitcoinExchange::parseLine(std::string const &line) {
    try {
        std::stringstream ss(line);
        // date
        std::string date;
        std::getline(ss, date, INPUT_DELIMITER_EDGE);
        Date d(date);
        // delimiter
        std::string delimiter;
        std::getline(ss, delimiter, INPUT_DELIMITER_EDGE);
        validateDelimiter(delimiter);
        // value
        std::string value;
        std::getline(ss, value);
        double v = parseValue(value);
        displayResult(d, v);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void BitcoinExchange::displayResult(Date const &date, double const &value) {
    std::map<Date, double>::iterator it = database.upper_bound(date);
    if (it == database.begin()) {
        throw std::out_of_range("Error: no data");
    }
    double rate = (--it)->second;
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

double BitcoinExchange::parseDouble(std::string const &number) {
    char *end;
    double d = std::strtod(number.c_str(), &end);
    if (*end != '\0') {
        throw std::invalid_argument("Error: " + number + " is invalid number.");
    }
    return d;
}

double BitcoinExchange::parseValue(std::string const &value) {
    double v = parseDouble(value);
    if (v <= 0.0) {
        throw std::invalid_argument("Error: " + value + " is not positive.");
    }
    if (v > 1000.0) {
        throw std::invalid_argument("Error: " + value + " is too large.");
    }
    return v;
}

void BitcoinExchange::validateDelimiter(std::string const &delimiter) {
    if (delimiter != INPUT_DELIMITER_MID) {
        throw std::invalid_argument("Error: invalid input format.");
    }
}

double BitcoinExchange::parseRate(std::string const &rate) {
    double r = parseDouble(rate);
    if (r < 0.0) {
        throw std::invalid_argument("Error: " + rate + " is a invalid exchange rate.");
    }
    return r;
}