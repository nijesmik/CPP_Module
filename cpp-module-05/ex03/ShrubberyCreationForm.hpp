//
// Created by Sejin Kim on 6/27/24.
//

#ifndef CPP_MODULE_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_CREATION_FORM_SIGN_GRADE 145
#define SHRUBBERY_CREATION_FORM_EXECUTE_GRADE 137

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string formName);
    ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
    virtual ~ShrubberyCreationForm();

    void execute(const Bureaucrat &executor) const;

    class FileOpenException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif //CPP_MODULE_SHRUBBERYCREATIONFORM_HPP
