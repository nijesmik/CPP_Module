//
// Created by 김세진 on 5/11/24.
//

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "🥲 empty";
    }
    std::cout << "🧠 it has a brain." << std::endl;
}

Brain::~Brain() {
    std::cout << "🧠 (I want to go home...)" << std::endl;
}

Brain::Brain(const Brain &brain) {
    *this = brain;
    std::cout << "🧠 A brain has been cloned." << std::endl;
}

Brain &Brain::operator=(const Brain &that) {
    if (this != &that) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = that.ideas[i];
        }
    }
    return *this;
}

void Brain::printIdea(int index) const {
    if (index < 0 || index >= 100) {
        std::cout << "🙅 invalid index" << std::endl;
    }
    std::cout << ideas[index] << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
    if (index < 0 || index >= 100) {
        std::cout << "🙅 invalid index" << std::endl;
    }
    ideas[index] = idea;
}
