//
// Created by Sejin Kim on 6/27/24.
//

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

bool RobotomyRequestForm::isSrandSeeded = false;

RobotomyRequestForm::RobotomyRequestForm()
        : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_FORM_SIGN_GRADE, ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE) {}

RobotomyRequestForm::RobotomyRequestForm(std::string formName)
        : AForm(formName, ROBOTOMY_REQUEST_FORM_SIGN_GRADE, ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
        : AForm(robotomyRequestForm) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm) {
    if (this != &robotomyRequestForm) {
        setName(robotomyRequestForm.getName());
        setIsSigned(robotomyRequestForm.getIsSigned());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExecuteGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }

    std::cout << "🔊 Drilling noise..." << std::endl;
    if (!isSrandSeeded) {
        std::srand(std::time(0));
        isSrandSeeded = true;
    }
    if (std::rand() % 2) {
        std::cout << "🤖 " << this->getName() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "🤖 " << this->getName() << " has failed to be robotomized" << std::endl;
    }
}
