//
// Created by Sejin Kim on 6/27/24.
//

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
        : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_FORM_SIGN_GRADE, SHRUBBERY_CREATION_FORM_EXECUTE_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string formName)
        : AForm(formName, SHRUBBERY_CREATION_FORM_SIGN_GRADE, SHRUBBERY_CREATION_FORM_EXECUTE_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm)
        : AForm(shrubberyCreationForm) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
    if (this != &shrubberyCreationForm) {
        setName(shrubberyCreationForm.getName());
        setIsSigned(shrubberyCreationForm.getIsSigned());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExecuteGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }

    std::string fileName = this->getName() + "_shrubbery";
    std::ofstream file(fileName);
    if (!file.is_open()) {
        throw ShrubberyCreationForm::FileOpenException();
    }
    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\" << std::endl;
    std::cout << "💾 " << fileName << " has been created" << std::endl;
    file.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "File open error";
}
