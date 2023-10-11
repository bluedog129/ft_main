#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void hyojocho()
{
    system("leaks ex02");
}

int main()
{
    Bureaucrat vipBureaucrat("vip_bureaucrat", 1);
    Bureaucrat normalBureaucrat("normal_bureaucrat", 50);
    Bureaucrat poorBureaucrat("poor_bureaucrat", 150);

    AForm *shrubberyCreationForm = new ShrubberyCreationForm("home");
    AForm *robotomyRequestForm = new RobotomyRequestForm("robot");
    AForm *presidentialPardonForm = new PresidentialPardonForm("president");

    std::cout << std::endl;
    std::cout << "---------------- poorBureaucrat ----------------" << std::endl;
    std::cout << std::endl;

    std::cout << poorBureaucrat << std::endl;
    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    poorBureaucrat.signForm(*shrubberyCreationForm);
    poorBureaucrat.signForm(*robotomyRequestForm);
    poorBureaucrat.signForm(*presidentialPardonForm);

    poorBureaucrat.executeForm(*shrubberyCreationForm);
    poorBureaucrat.executeForm(*robotomyRequestForm);
    poorBureaucrat.executeForm(*presidentialPardonForm);

    std::cout << std::endl;

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------------- normalBureaucrat ----------------" << std::endl;
    std::cout << std::endl;

    std::cout << normalBureaucrat << std::endl;
    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    std::cout << std::endl;

    normalBureaucrat.signForm(*shrubberyCreationForm);
    normalBureaucrat.signForm(*robotomyRequestForm);
    normalBureaucrat.signForm(*presidentialPardonForm);

    std::cout << std::endl;

    normalBureaucrat.executeForm(*shrubberyCreationForm);
    normalBureaucrat.executeForm(*robotomyRequestForm);
    normalBureaucrat.executeForm(*presidentialPardonForm);

    std::cout << std::endl;

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;
    std::cout << std::endl;


    std::cout << std::endl;
    std::cout << "---------------- vipBureaucrat ----------------" << std::endl;
    std::cout << std::endl;

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    vipBureaucrat.signForm(*shrubberyCreationForm);
    vipBureaucrat.signForm(*robotomyRequestForm);
    vipBureaucrat.signForm(*presidentialPardonForm);

    std::cout << std::endl;
    std::cout << std::endl;

    vipBureaucrat.executeForm(*shrubberyCreationForm);
    vipBureaucrat.executeForm(*robotomyRequestForm);
    vipBureaucrat.executeForm(*presidentialPardonForm);

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    std::cout << std::endl;

    delete shrubberyCreationForm;
    delete robotomyRequestForm;
    delete presidentialPardonForm;


    hyojocho();
    return (0);
}