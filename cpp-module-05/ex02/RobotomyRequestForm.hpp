//
// Created by Sejin Kim on 6/27/24.
//

#ifndef CPP_MODULE_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULE_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

#define ROBOTOMY_REQUEST_FORM_SIGN_GRADE 72
#define ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE 45

class RobotomyRequestForm : public AForm {
private:
    static bool isSrandSeeded;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string formName);
    RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
    virtual ~RobotomyRequestForm();

    void execute(const Bureaucrat &executor) const;
};

#endif //CPP_MODULE_ROBOTOMYREQUESTFORM_HPP
