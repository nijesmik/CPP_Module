//
// Created by 김세진 on 7/9/24.
//

#ifndef CPP_MODULE_EASYFIND_HPP
#define CPP_MODULE_EASYFIND_HPP

#include <iterator>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "Not Found";
    }
};

// assuming that T is a container of integers
template<typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

#endif //CPP_MODULE_EASYFIND_HPP
