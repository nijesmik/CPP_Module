//
// Created by Sejin Kim on 6/27/24.
//

#ifndef CPP_MODULE_BUREAUCRAT_HPP
#define CPP_MODULE_BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
private:
    std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
    void signForm(class AForm &form);
    void executeForm(class AForm const &form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif //CPP_MODULE_BUREAUCRAT_HPP
