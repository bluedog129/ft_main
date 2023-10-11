#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    std::string _target;
public:
    Intern();
    Intern(std::string target);
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    std::string getTarget() const;
    void setTarget(std::string target);
    AForm *makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif