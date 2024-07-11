//
// Created by 김세진 on 7/11/24.
//

#ifndef CPP_MODULE_RPN_HPP
#define CPP_MODULE_RPN_HPP

#include <stack>
#include <sstream>
#include <string>
#include <iostream>

class RPN {
private:
    std::stack<long> stack;

    void clear();
    long pop();
    long parseLong(const std::string &str);
    void calculate(char const _operator, long const &a, long const &b);
    void divide(long const &a, long const &b);

public:
    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN &operator=(const RPN &other);

    void calculate(std::string const &expression);
};

#endif //CPP_MODULE_RPN_HPP
