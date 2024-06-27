//
// Created by 김세진 on 6/28/24.
//

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
        : AForm("PresidentialPardonForm", PRESIDENTIAL_PARDON_FORM_SIGN_GRADE,
                PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(std::string formName)
        : AForm(formName, PRESIDENTIAL_PARDON_FORM_SIGN_GRADE, PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
        : AForm(presidentialPardonForm) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm) {
    if (this != &presidentialPardonForm) {
        AForm::operator=(presidentialPardonForm);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExecuteGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }

    std::cout << "⚖️ " << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
