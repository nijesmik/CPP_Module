//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_DOG_HPP
#define CPP_MODULE_DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // ocf
    Dog();
    ~Dog();
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);

    // methods
    void makeSound() const;
};

#endif //CPP_MODULE_DOG_HPP
