//
// Created by Sejin Kim on 6/27/24.
//

#ifndef CPP_MODULE_FORM_HPP
#define CPP_MODULE_FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

public:
    Form();
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form &form);
    Form &operator=(const Form &form);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif //CPP_MODULE_FORM_HPP
