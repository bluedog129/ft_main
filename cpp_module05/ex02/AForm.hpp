#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    virtual ~Form() = 0;
    
    virtual std::string getName() const = 0;
    virtual bool getSigned() const = 0;
    virtual int getGradeToSign() const = 0;
    virtual int getGradeToExecute() const = 0;
    virtual void beSigned(const Bureaucrat &bureaucrat) = 0;

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

    friend std::ostream &operator<<(std::ostream &out, const Form &form);
};

#endif