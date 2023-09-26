#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("default", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    Form::operator=(copy);
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

bool PresidentialPardonForm::getSigned() const
{
    return (Form::getSigned());
}

int PresidentialPardonForm::getGradeToSign() const
{
    return (Form::getGradeToSign());
}

int PresidentialPardonForm::getGradeToExecute() const
{
    return (Form::getGradeToExecute());
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
    Form::beSigned(bureaucrat);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();
    if (!getSigned())
        throw Form::FormNotSignedException();
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}


