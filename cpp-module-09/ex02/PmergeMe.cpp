//
// Created by 김세진 on 7/14/24.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : size(0), jacobsthal(NULL) {}

PmergeMe::PmergeMe(char **input, int size) : size(size) {
    char *end;
    for (int i = 0; i < size; i++) {
        long num = strtol(input[i], &end, 10);
        if (*end != '\0' || num <= 0) {
            throw std::invalid_argument("ERROR: invalid input");
        }
        vector.push_back(num);
        deque.push_back(num);
    }

    int N = (size + 1) / 2 + 1;
    jacobsthal = new int[N];
    jacobsthal[0] = 0;
    for (int i = 1; i < N; i++) {
        jacobsthal[i] = getJacobsthalNumber(i);
    }
}

PmergeMe::PmergeMe(const PmergeMe &other) : size(other.size), vector(other.vector), deque(other.deque) {
    int N = (size + 1) / 2 + 1;
    jacobsthal = new int[N];
    for (int i = 0; i < N; i++) {
        jacobsthal[i] = other.jacobsthal[i];
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    vector = other.vector;
    deque = other.deque;
    if (jacobsthal) {
        delete[] jacobsthal;
    }
    int N = (size + 1) / 2 + 1;
    jacobsthal = new int[N];
    for (int i = 0; i < N; i++) {
        jacobsthal[i] = other.jacobsthal[i];
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    if (jacobsthal) {
        delete[] jacobsthal;
    }
}

int PmergeMe::getJacobsthalNumber(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 3;
    }
    return jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
}

int PmergeMe::getJacobsthalIndex(int i, int max) {
    int j = jacobsthal[i];
    if (j >= max) {
        return max - 1;
    }
    return j - 1;
}

void PmergeMe::sortWithVector() {
    sortWith(vector, "std::vector");
}

void PmergeMe::sortWithDeque() {
    sortWith(deque, "std::deque");
}

double PmergeMe::getTime(clock_t start) {
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::displayTime(double time, std::string containerName) {
    std::cout << "Time to process a range of " << size
              << " elements with " << containerName
              << " : " << time << " us" << std::endl;
}
