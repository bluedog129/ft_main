#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("default", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    Form::operator=(copy);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

bool ShrubberyCreationForm::getSigned() const
{
    return (Form::getSigned());
}

int ShrubberyCreationForm::getGradeToSign() const
{
    return (Form::getGradeToSign());
}

int ShrubberyCreationForm::getGradeToExecute() const
{
    return (Form::getGradeToExecute());
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
    Form::beSigned(bureaucrat);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();
    if (!getSigned())
        throw Form::FormNotSignedException();
    std::ofstream ofs(getTarget() + "_shrubbery");
}