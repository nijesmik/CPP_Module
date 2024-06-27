//
// Created by Sejin Kim on 6/27/24.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat newbie("신입사원", 150);
    Bureaucrat ceo("대표이사", 1);
    ShrubberyCreationForm shrubberyCreationForm;

    newbie.executeForm(shrubberyCreationForm);

    ceo.executeForm(shrubberyCreationForm);

    ceo.signForm(shrubberyCreationForm);
    ceo.executeForm(shrubberyCreationForm);

    RobotomyRequestForm robotomyRequestForm;
    ceo.signForm(robotomyRequestForm);
    ceo.executeForm(robotomyRequestForm);

    PresidentialPardonForm presidentialPardonForm;
    ceo.signForm(presidentialPardonForm);
    ceo.executeForm(presidentialPardonForm);

    return 0;
}