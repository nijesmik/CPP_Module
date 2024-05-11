//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_ANIMAL_HPP
#define CPP_MODULE_ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;

public:
    // ocf
    Animal();
    Animal(std::string type);
    virtual ~Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);

    // methods
    virtual void makeSound() const;
    std::string getType() const;
};

#endif //CPP_MODULE_ANIMAL_HPP
