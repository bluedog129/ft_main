#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return (_target);
}

std::string PresidentialPardonForm::getName() const
{
    return (AForm::getName());
}

bool PresidentialPardonForm::getSigned() const
{
    return (AForm::getSigned());
}

int PresidentialPardonForm::getGradeToSign() const
{
    return (AForm::getGradeToSign());
}

int PresidentialPardonForm::getGradeToExecute() const
{
    return (AForm::getGradeToExecute());
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
    AForm::beSigned(bureaucrat);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!getSigned())
        throw AForm::FormNotSignedException();
    std::cout << "lalalala" << std::endl;
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
