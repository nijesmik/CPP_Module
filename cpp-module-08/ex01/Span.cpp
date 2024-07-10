//
// Created by 김세진 on 7/9/24.
//

#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span &other) : size(other.size), vec(other.vec) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    vec = other.vec;
    return *this;
}

void Span::addNumber(int n) {
    if (vec.size() >= size) {
        throw NoStorageException();
    }
    vec.push_back(n);
}

int Span::shortestSpan() {
    if (vec.size() < 2) {
        throw TooFewNumbersException();
    }
    std::vector<int> sorted(vec);
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (std::vector<int>::iterator it = sorted.begin() + 2; it != sorted.end(); ++it) {
        int span = *it - *(it - 1);
        if (span < min) {
            min = span;
        }
    }
    return min;
}

int Span::longestSpan() {
    if (vec.size() < 2) {
        throw TooFewNumbersException();
    }
    int maxElement = *std::max_element(vec.begin(), vec.end());
    int minElement = *std::min_element(vec.begin(), vec.end());
    return maxElement - minElement;
}
