//
// Created by 김세진 on 7/11/24.
//

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
    if (this == &other) {
        return *this;
    }
    stack = other.stack;
    return *this;
}

void RPN::calculate(std::string const &expression) {
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                clear();
                throw std::runtime_error("Error: invalid expression.");
            }
            calculate(token[0], pop(), pop());
        } else {
            stack.push(parseLong(token));
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }
    std::cout << stack.top() << std::endl;
}

void RPN::clear() {
    while (!stack.empty()) {
        stack.pop();
    }
}

long RPN::pop() {
    if (stack.empty()) {
        throw std::runtime_error("Error: stack is empty.");
    }
    long top = stack.top();
    stack.pop();
    return top;
}

long RPN::parseLong(const std::string &str) {
    char *end;
    long num = strtol(str.c_str(), &end, 10);
    if (*end != '\0') {
        clear();
        throw std::runtime_error("Error: invalid expression.");
    }
    return num;
}

void RPN::calculate(char const _operator, long const &a, long const &b) {
    switch (_operator) {
        case '+':
            return stack.push(b + a);
        case '-':
            return stack.push(b - a);
        case '*':
            return stack.push(b * a);
        case '/':
            return divide(a, b);
    }
}

void RPN::divide(long const &a, long const &b) {
    if (a == 0) {
        clear();
        throw std::runtime_error("Error: division by zero.");
    }
    stack.push(b / a);
}
