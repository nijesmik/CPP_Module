//
// Created by 김세진 on 7/9/24.
//

#ifndef CPP_MODULE_SPAN_HPP
#define CPP_MODULE_SPAN_HPP

#include <vector>

class Span {
private:
    unsigned int size;
    std::vector<int> vec;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    ~Span();
    Span &operator=(const Span &other);

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    class NoStorageException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "no storage left";
        }
    };

    class TooFewNumbersException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "cannot find span with less than 2 stored numbers";
        }
    };
};

#endif //CPP_MODULE_SPAN_HPP
