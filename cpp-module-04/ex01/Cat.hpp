//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_CAT_HPP
#define CPP_MODULE_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *brain;

public:
    // ocf
    Cat();
    ~Cat();
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);

    // methods
    void makeSound() const;
    Brain *getBrain() const;
};

#endif //CPP_MODULE_CAT_HPP
