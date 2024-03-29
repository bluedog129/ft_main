#ifndef BUROCRAT_HPP
#define BUROCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();
    
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form) const;
    void executeForm(AForm const & form) const;

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
    friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
};

#endif