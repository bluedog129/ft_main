#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &copy);
    virtual ~AForm() = 0;
    
    virtual std::string getName() const = 0;
    virtual bool getSigned() const = 0;
    virtual int getGradeToSign() const = 0;
    virtual int getGradeToExecute() const = 0;
    virtual void beSigned(const Bureaucrat &bureaucrat) = 0;
    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    friend std::ostream &operator<<(std::ostream &out, const AForm &form);
};

#endif