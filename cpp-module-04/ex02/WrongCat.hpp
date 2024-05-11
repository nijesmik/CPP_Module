//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_WRONGCAT_HPP
#define CPP_MODULE_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // ocf
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &wrongCat);
    WrongCat &operator=(const WrongCat &wrongCat);

    // methods
    void makeSound() const;
};

#endif //CPP_MODULE_WRONGCAT_HPP
