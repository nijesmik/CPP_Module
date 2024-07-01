//
// Created by Sejin Kim on 6/27/24.
//

#ifndef CPP_MODULE_AFORM_HPP
#define CPP_MODULE_AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

protected:
    void setName(std::string name);
    void setIsSigned(bool isSigned);

public:
    AForm();
    AForm(std::string name, int signGrade, int executeGrade);
    AForm(const AForm &form);
    AForm &operator=(const AForm &form);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

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

    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif //CPP_MODULE_AFORM_HPP
