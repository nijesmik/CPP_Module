//
// Created by 김세진 on 6/28/24.
//

#ifndef CPP_MODULE_INTERN_HPP
#define CPP_MODULE_INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    ~Intern();

    AForm *makeForm(std::string formType, std::string formName);

    class InvalidFormTypeException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    AForm *createShrubberyCreationForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createPresidentialPardonForm(std::string target);
};

#endif //CPP_MODULE_INTERN_HPP
