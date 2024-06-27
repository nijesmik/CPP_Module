//
// Created by Sejin Kim on 6/27/24.
//

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat ceo("대표이사", 1);
    Intern intern;

    std::string formTypes[] = {
            "ShrubberyCreationForm",
            "RobotomyRequestForm",
            "PresidentialPardonForm",
            "InvalidForm"
    };

    try {
        for (int i = 0; i < 4; i++) {
            AForm *form = intern.makeForm(formTypes[i], formTypes[i]);
            ceo.signForm(*form);
            ceo.executeForm(*form);
            delete form;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}