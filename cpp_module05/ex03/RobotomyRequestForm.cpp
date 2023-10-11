#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
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

std::string RobotomyRequestForm::getName() const
{
    return (AForm::getName());
}

bool RobotomyRequestForm::getSigned() const
{
    return (AForm::getSigned());
}

int RobotomyRequestForm::getGradeToSign() const
{
    return (AForm::getGradeToSign());
}

int RobotomyRequestForm::getGradeToExecute() const
{
    return (AForm::getGradeToExecute());
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
    AForm::beSigned(bureaucrat);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!getSigned())
        throw AForm::FormNotSignedException();
    std::cout << "* drilling noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << getTarget() << " robotomization failed" << std::endl;
}

