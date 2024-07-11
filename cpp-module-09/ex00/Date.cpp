//
// Created by 김세진 on 7/10/24.
//

#include "Date.hpp"

Date::Date() : year(0), month(0), day(0) {}

Date::Date(std::string const &date) {
    std::stringstream ss(date);
    year = parseYear(ss, date);
    month = parseMonth(ss, date);
    day = parseDay(ss, date);
}

Date::Date(const Date &other) : year(other.year), month(other.month), day(other.day) {}

Date::~Date() {}

Date &Date::operator=(const Date &other) {
    if (this == &other) {
        return *this;
    }
    year = other.year;
    month = other.month;
    day = other.day;
    return *this;
}

bool Date::operator<(const Date &other) const {
    return (year < other.year) ||
           (year == other.year && month < other.month) ||
           (year == other.year && month == other.month && day < other.day);
}

bool Date::operator>(const Date &other) const {
    return (other < *this);
}

bool Date::operator<=(const Date &other) const {
    return !(*this > other);
}

bool Date::operator>=(const Date &other) const {
    return !(*this < other);
}

bool Date::operator==(const Date &other) const {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date &other) const {
    return !(*this == other);
}

int Date::parseInt(std::stringstream &ss, size_t const size, std::string const &date) {
    std::string number;
    std::getline(ss, number, DATE_DELIMITER);
    if (number.length() != size) {
        throw std::runtime_error("Error: " + date + " is not a valid date format. (YYYY-MM-DD)");
    }
    char *end;
    long parsedNumber = strtol(number.c_str(), &end, 10);
    if (*end != '\0') {
        throw std::runtime_error("Error: " + date + " is not a valid date format. (YYYY-MM-DD)");
    }
    return static_cast<int>(parsedNumber);
}

int Date::parseYear(std::stringstream &ss, const std::string &date) {
    int y = parseInt(ss, 4, date);
    if (y < 0) {
        throw std::runtime_error("Error: " + date + " has a invalid year.");
    }
    return y;
}

int Date::parseMonth(std::stringstream &ss, const std::string &date) {
    int m = parseInt(ss, 2, date);
    if (m < 1 || m > 12) {
        throw std::runtime_error("Error: " + date + " has a invalid month.");
    }
    return m;
}

int Date::parseDay(std::stringstream &ss, const std::string &date) {
    int d = parseInt(ss, 2, date);
    if (d < 1 || d > 31) {
        throw std::runtime_error("Error: " + date + " has a invalid day.");
    }
    if (((month < 8 && month % 2 == 0) || (month > 7 && month % 2 == 1)) && d == 31) {
        throw std::runtime_error(
                "Error: " + date + " has a invalid day for month " + std::to_string(month) + ".");
    }
    if (month == 2 && d > 28 + static_cast<int>(isLeapYear())) {
        throw std::runtime_error(
                "Error: " + date + " has a invalid day for month " + std::to_string(month) + ".");
    }
    return d;
}

bool Date::isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.getYear() << DATE_DELIMITER;
    if (date.getMonth() < 10) {
        os << "0";
    }
    os << date.getMonth() << DATE_DELIMITER;
    if (date.getDay() < 10) {
        os << "0";
    }
    os << date.getDay();
    return os;
}
