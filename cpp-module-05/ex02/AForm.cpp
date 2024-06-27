//
// Created by Sejin Kim on 6/27/24.
//

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("form"), isSigned(false), signGrade(150), executeGrade(150) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade),
                                                                  executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1) {
        throw AForm::GradeTooHighException();
    } else if (signGrade > 150 || executeGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &form) : name(form.name), isSigned(form.isSigned), signGrade(form.signGrade),
                                  executeGrade(form.executeGrade) {}

AForm &AForm::operator=(const AForm &form) {
    if (this != &form) {
        this->name = form.name;
        this->isSigned = form.isSigned;
        this->signGrade = form.signGrade;
        this->executeGrade = form.executeGrade;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getSignGrade() const {
    return this->signGrade;
}

int AForm::getExecuteGrade() const {
    return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->signGrade) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (this->isSigned) {
        throw AForm::FormAlreadySignedException();
    }
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade of form is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade of form is too low";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
    return "Form is already signed";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << form.getName() << " is ";
    if (!form.getIsSigned()) {
        out << "not ";
    }
    out << "signed. Sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade();
    return out;
}
