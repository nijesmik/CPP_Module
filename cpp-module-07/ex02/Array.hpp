//
// Created by 김세진 on 7/9/24.
//

#ifndef CPP_MODULE_ARRAY_HPP
#define CPP_MODULE_ARRAY_HPP

#include <cstddef>
#include <exception>

template<typename T>
class Array {
private:
    unsigned int _size;
    T *array;

public:
    Array() : _size(0), array(NULL) {}

    Array(unsigned int n) : _size(n) {
        if (!n) {
            array = NULL;
            return;
        }
        array = new T[n]();
    }

    Array(const Array &other) : _size(other._size) {
        if (!other._size) {
            array = NULL;
            return;
        }
        array = new T[other._size];
        for (unsigned int i = 0; i < _size; i++) {
            array[i] = other.array[i];
        }
    }

    ~Array() {
        if (array) {
            delete[] array;
        }
    }

    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }
        if (_size) {
            delete[] array;
        }
        _size = other._size;
        if (!other._size) {
            array = NULL;
            return *this;
        }
        array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            array[i] = other.array[i];
        }
        return *this;
    }

    T &operator[](unsigned int i) {
        if (i >= _size) {
            throw OutOfRangeException();
        }
        return array[i];
    }

    const T &operator[](unsigned int i) const {
        if (i >= _size) {
            throw OutOfRangeException();
        }
        return array[i];
    }

    unsigned int size() const {
        return _size;
    }

    class OutOfRangeException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Index out of range";
        }
    };
};

#endif //CPP_MODULE_ARRAY_HPP
