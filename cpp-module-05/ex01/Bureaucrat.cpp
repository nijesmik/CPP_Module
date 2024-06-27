//
// Created by Sejin Kim on 6/27/24.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
        this->name = bureaucrat.name;
        this->grade = bureaucrat.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::increaseGrade() {
    if (this->grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decreaseGrade() {
    if (this->grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade of bureaucrat is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade of bureaucrat is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
