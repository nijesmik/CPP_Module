//
// Created by 김세진 on 6/28/24.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
    (void) intern;
}

Intern &Intern::operator=(const Intern &intern) {
    (void) intern;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formType, std::string formName) {
    typedef AForm *(Intern::*CreateFormFunction)(std::string);

    std::string formTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    CreateFormFunction createForm[] = {
            &Intern::createShrubberyCreationForm,
            &Intern::createRobotomyRequestForm,
            &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formType) {
            return (this->*createForm[i])(formName);
        }
    }

    throw InvalidFormTypeException();
}

AForm *Intern::createShrubberyCreationForm(std::string formName) {
    return new ShrubberyCreationForm(formName);
}

AForm *Intern::createRobotomyRequestForm(std::string formName) {
    return new RobotomyRequestForm(formName);
}

AForm *Intern::createPresidentialPardonForm(std::string formName) {
    return new PresidentialPardonForm(formName);
}

const char *Intern::InvalidFormTypeException::what() const throw() {
    return "Type of form is invalid";
}
