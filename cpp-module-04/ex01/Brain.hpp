//
// Created by 김세진 on 5/11/24.
//

#ifndef CPP_MODULE_BRAIN_HPP
#define CPP_MODULE_BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string ideas[100];
public:
    // ocf
    Brain();
    Brain(const Brain &brain);
    Brain &operator=(const Brain &brain);
    ~Brain();

    // methods
    void printIdea(int index) const;
    void setIdea(int index, std::string idea);
};

#endif //CPP_MODULE_BRAIN_HPP
