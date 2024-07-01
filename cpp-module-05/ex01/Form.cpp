//
// Created by Sejin Kim on 6/27/24.
//

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade),
                                                                executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signGrade > 150 || executeGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &form) : name(form.name), isSigned(form.isSigned), signGrade(form.signGrade),
                               executeGrade(form.executeGrade) {}

Form &Form::operator=(const Form &form) {
    if (this != &form) {
        const_cast<std::string &>(this->name) = form.name;
        this->isSigned = form.isSigned;
        const_cast<int &>(this->signGrade) = form.signGrade;
        const_cast<int &>(this->executeGrade) = form.executeGrade;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getSignGrade() const {
    return this->signGrade;
}

int Form::getExecuteGrade() const {
    return this->executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->signGrade) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (this->isSigned) {
        throw Form::FormAlreadySignedException();
    }
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade of form is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade of form is too low";
}

const char *Form::FormAlreadySignedException::what() const throw() {
    return "Form is already signed";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << form.getName() << " is ";
    if (!form.getIsSigned()) {
        out << "not ";
    }
    out << "signed. Sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade();
    return out;
}
