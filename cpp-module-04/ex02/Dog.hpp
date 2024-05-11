//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_DOG_HPP
#define CPP_MODULE_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *brain;

public:
    // ocf
    Dog();
    ~Dog();
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);

    // methods
    void makeSound() const;
    Brain *getBrain() const;
};

#endif //CPP_MODULE_DOG_HPP
