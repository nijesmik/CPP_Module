//
// Created by 김세진 on 6/28/24.
//

#ifndef CPP_MODULE_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULE_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PRESIDENTIAL_PARDON_FORM_SIGN_GRADE 25
#define PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE 5

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string formName);
    PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
    virtual ~PresidentialPardonForm();

    void execute(const Bureaucrat &executor) const;
};

#endif //CPP_MODULE_PRESIDENTIALPARDONFORM_HPP
