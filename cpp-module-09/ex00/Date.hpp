//
// Created by 김세진 on 7/10/24.
//

#ifndef CPP_MODULE_DATE_HPP
#define CPP_MODULE_DATE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#define DATE_DELIMITER '-'

class Date {
private:
    int year;
    int month;
    int day;

    Date();

    int parseInt(std::stringstream &ss, size_t const size, std::string const &date);
    int parseYear(std::stringstream &ss, std::string const &date);
    int parseMonth(std::stringstream &ss, std::string const &date);
    int parseDay(std::stringstream &ss, std::string const &date);

public:
    Date(std::string const &date);
    Date(const Date &other);
    ~Date();
    Date &operator=(const Date &other);

    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;

    bool isLeapYear();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
};

std::ostream &operator<<(std::ostream &os, const Date &date);

#endif //CPP_MODULE_DATE_HPP
