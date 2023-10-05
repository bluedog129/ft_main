#include "Intern.hpp"

Intern::Intern() : _name("default"), _target("default")
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(std::string name, std::string target) : _name(name), _target(target)
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) : _name(copy._name), _target(copy._target)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_name = copy._name;
    this->_target = copy._target;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

std::string Intern::getName() const
{
    return (_name);
}

std::string Intern::getTarget() const
{
    return (_target);
}

void Intern::setName(std::string name)
{
    this->_name = name;
}

void Intern::setTarget(std::string target)
{
    this->_target = target;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    int formType = 0;

    while (1)
    {
        if (formName == "ShrubberyCreationForm")
        {
            formType = 1;
            break;
        }
        else if (formName == "RobotomyRequestForm")
        {
            formType = 2;
            break;
        }
        else if (formName == "PresidentialPardonForm")
        {
            formType = 3;
            break;
        }
        else
            throw Intern::FormNotFoundException();
    }
    switch (formType)
    {
        case 1:
            form = new ShrubberyCreationForm(target);
            break;
        case 2:
            form = new RobotomyRequestForm(target);
            break;
        case 3:
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