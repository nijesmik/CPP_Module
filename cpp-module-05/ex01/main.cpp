//
// Created by Sejin Kim on 6/27/24.
//

#include "Bureaucrat.hpp"

int main() {
    try {
        Form form("사업 양도 계약서", 0, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form form("사업 양도 계약서", 1, 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Form form("사업 양도 계약서", 1, 1);
    std::cout << form << std::endl;

    Bureaucrat bureaucrat1("신입사원", 150);
    Bureaucrat bureaucrat2("대표이사", 1);
    bureaucrat1.signForm(form);
    bureaucrat2.signForm(form);
    bureaucrat2.signForm(form);
    std::cout << form << std::endl;

    return 0;
}