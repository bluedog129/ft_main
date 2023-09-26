#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("default", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    Form::operator=(copy);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

bool RobotomyRequestForm::getSigned() const
{
    return (Form::getSigned());
}

int RobotomyRequestForm::getGradeToSign() const
{
    return (Form::getGradeToSign());
}

int RobotomyRequestForm::getGradeToExecute() const
{
    return (Form::getGradeToExecute());
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
    Form::beSigned(bureaucrat);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();
    if (!getSigned())
        throw Form::FormNotSignedException();
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << getTarget() << " robotomization failed" << std::endl;
}

