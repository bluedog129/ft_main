#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
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

std::string ShrubberyCreationForm::getName() const
{
    return (AForm::getName());
}

bool ShrubberyCreationForm::getSigned() const
{
    return (AForm::getSigned());
}

int ShrubberyCreationForm::getGradeToSign() const
{
    return (AForm::getGradeToSign());
}

int ShrubberyCreationForm::getGradeToExecute() const
{
    return (AForm::getGradeToExecute());
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
    AForm::beSigned(bureaucrat);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!getSigned())
        throw AForm::FormNotSignedException();

    std::cout << "hyojocho" << std::endl;
    std::ofstream ofs(getTarget() + "_shrubbery");

    if (!ofs.is_open())
        throw std::runtime_error("hyojoch 효조치");

    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs << std::endl;
}