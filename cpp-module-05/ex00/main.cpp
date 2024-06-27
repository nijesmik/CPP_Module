//
// Created by Sejin Kim on 6/27/24.
//

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat bureaucrat1("대표이사", 1);
    std::cout << bureaucrat1 << std::endl;
    try {
        bureaucrat1.increaseGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat bureaucrat2("신입사원", 150);
    std::cout << bureaucrat2 << std::endl;
    try {
        bureaucrat2.decreaseGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}