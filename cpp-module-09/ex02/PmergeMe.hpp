//
// Created by 김세진 on 7/14/24.
//

#ifndef CPP_MODULE_PMERGEME_HPP
#define CPP_MODULE_PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class PmergeMe {
public:
    PmergeMe(char **input, int size);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortWithVector();
    void sortWithDeque();

private:
    int size;
    std::vector<long> vector;
    std::deque<long> deque;
    int *jacobsthal;

    PmergeMe();

    int getJacobsthalNumber(int n);
    int getJacobsthalIndex(int i, int max);
    double getTime(clock_t start);
    void displayTime(double time, std::string containerName);

    template<class Container>
    void display(Container &c) {
        typedef typename Container::iterator iterator;
        if (isSorted(c)) {
            std::cout << GREEN;
        } else {
            std::cout << RED;
        }
        for (iterator it = c.begin(); it != c.end(); it++) {
            std::cout << " " << *it;
        }
        std::cout << RESET << std::endl;
    }

    template<class Container>
    void sortWith(Container &c, std::string containerName) {
        std::cout << "Before : ";
        display(c);
//        displaySorted(c, containerName);
        clock_t start = clock();
        sort(c, size, 1);
        double time = getTime(start);
        std::cout << "After : ";
        display(c);
//        displaySorted(c, containerName);
        displayTime(time, containerName);
    }

    template<class Container>
    void sort(Container &c, int batchCount, int batchSize) {
        if (batchCount <= 1) {
            return;
        }
        compare(c, batchCount, batchSize);
        sort(c, batchCount / 2, batchSize * 2);
        insert(c, batchCount, batchSize);
    }

    template<class Container>
    void compare(Container &c, int batchCount, int batchSize) {
        typedef typename Container::iterator iterator;
        iterator it = c.begin();
        for (int i = 0; i < batchCount - 1; i += 2) {
            iterator prev = it + i * batchSize;
            iterator next = it + (i + 1) * batchSize;
            if (*prev < *next) {
                std::swap_ranges(prev, next, next);
            }
        }
    }

    template<class Container>
    void insert(Container &c, int batchCount, int batchSize) {
        Container main;
        Container sub;
        typedef typename Container::iterator iterator;
        iterator it = c.begin();
        for (int i = 0; i < batchCount; i++) {
            if (i % 2 == 0 && i != batchCount - 1) {
                main.insert(main.end(), it + i * batchSize, it + (i + 1) * batchSize);
            } else {
                sub.insert(sub.end(), it + i * batchSize, it + (i + 1) * batchSize);
            }
        }

        int insertCount = 0;
        int subSize = batchCount / 2 + batchCount % 2;
        for (int i = 1; jacobsthal[i - 1] < subSize; i++) {
            int idx = getJacobsthalIndex(i, subSize);
            for (int j = idx; j >= jacobsthal[i - 1]; j--) {
                binarySearchInsert(main, sub, j, insertCount++, batchSize);
            }
        }
        for (iterator i = c.begin() + main.size(); i != c.end(); i++) {
            main.push_back(*i);
        }
        c = main;
    }

    template<class Container>
    void binarySearchInsert(Container &main, Container &sub, int idx, int insertCount, int batchSize) {
        typedef typename Container::iterator iterator;
        iterator mainIt = main.begin();
        iterator subIt = sub.begin() + idx * batchSize;
        if (idx == 0) {
            main.insert(mainIt, subIt, subIt + batchSize);
            return;
        }
        int left = 0;
        int right = idx + insertCount;
        while (left < right) {
            int mid = (left + right) / 2;
            if (main[mid * batchSize] < *subIt) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        main.insert(mainIt + left * batchSize, subIt, subIt + batchSize);
    }

    template<class Container>
    bool isSorted(Container c) {
        typedef typename Container::iterator iterator;
        iterator it = c.begin();
        iterator prev = it++;
        while (it != c.end()) {
            if (*prev > *it) {
                return false;
            }
            prev = it++;
        }
        return true;
    }

    template<class Container>
    void displaySorted(Container &c, std::string containerName) {
        if (isSorted(c)) {
            std::cout << GREEN << "a range of " << size
                      << " elements with " << containerName
                      << " is sorted" << RESET << std::endl;
            return;
        }
        std::cout << RED << "a range of " << size
                  << " elements with " << containerName
                  << " is not sorted" << RESET << std::endl;
    }
};

#endif //CPP_MODULE_PMERGEME_HPP
