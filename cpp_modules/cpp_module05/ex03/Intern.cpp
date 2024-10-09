#include "Intern.hpp"

Intern::Intern() : _target("default")
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(std::string target) : _target(target)
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) : _target(copy._target)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_target = copy._target;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

std::string Intern::getTarget() const
{
    return (_target);
}

void Intern::setTarget(std::string target)
{
    this->_target = target;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    int formType = 0;
    std::string arr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    
    for (formType = 0; formType < 3; formType++)
    {
        if (arr[formType] == formName)
            break;
    }
    switch (formType)
    {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotFoundException();
    }
    std::cout << "Intern creates " << form->getName() << std::endl;
    return (form);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}