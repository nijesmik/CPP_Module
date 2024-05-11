//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_WRONGANIMAL_HPP
#define CPP_MODULE_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    // ocf
    WrongAnimal();
    WrongAnimal(std::string type);
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal &wrongAnimal);
    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

    // methods
    void makeSound() const;
    std::string getType() const;
};

#endif //CPP_MODULE_WRONGANIMAL_HPP
