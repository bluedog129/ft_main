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

    // std::cout << std::endl;
    // std::cout << "---------------- poorBureaucrat ----------------" << std::endl;
    // std::cout << std::endl;

    // std::cout << poorBureaucrat << std::endl;
    // std::cout << *shrubberyCreationForm << std::endl;
    // std::cout << *robotomyRequestForm << std::endl;
    // std::cout << *presidentialPardonForm << std::endl;

    // try {
    //     shrubberyCreationForm->beSigned(poorBureaucrat);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // try {
    //     robotomyRequestForm->beSigned(poorBureaucrat);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // try {
    //     presidentialPardonForm->beSigned(poorBureaucrat);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << std::endl;
    // std::cout << std::endl;

    // poorBureaucrat.signForm(shrubberyCreationForm->getSigned(), shrubberyCreationForm->getName());
    // poorBureaucrat.signForm(robotomyRequestForm->getSigned(), robotomyRequestForm->getName());
    // poorBureaucrat.signForm(presidentialPardonForm->getSigned(), presidentialPardonForm->getName());

    // poorBureaucrat.executeForm(*shrubberyCreationForm);
    // poorBureaucrat.executeForm(*robotomyRequestForm);
    // poorBureaucrat.executeForm(*presidentialPardonForm);

    // std::cout << std::endl;

    // std::cout << *shrubberyCreationForm << std::endl;
    // std::cout << *robotomyRequestForm << std::endl;
    // std::cout << *presidentialPardonForm << std::endl;
    // std::cout << std::endl;

    // std::cout << std::endl;
    // std::cout << "---------------- normalBureaucrat ----------------" << std::endl;
    // std::cout << std::endl;

    // std::cout << normalBureaucrat << std::endl;
    // std::cout << *shrubberyCreationForm << std::endl;
    // std::cout << *robotomyRequestForm << std::endl;
    // std::cout << *presidentialPardonForm << std::endl;

    // try {
    //     shrubberyCreationForm->beSigned(normalBureaucrat);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // try {
    //     robotomyRequestForm->beSigned(normalBureaucrat);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // try {
    //     presidentialPardonForm->beSigned(normalBureaucrat);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << std::endl;

    // normalBureaucrat.signForm(shrubberyCreationForm->getSigned(), shrubberyCreationForm->getName());
    // normalBureaucrat.signForm(robotomyRequestForm->getSigned(), robotomyRequestForm->getName());
    // normalBureaucrat.signForm(presidentialPardonForm->getSigned(), presidentialPardonForm->getName());

    // std::cout << std::endl;

    // normalBureaucrat.executeForm(*shrubberyCreationForm);
    // normalBureaucrat.executeForm(*robotomyRequestForm);
    // normalBureaucrat.executeForm(*presidentialPardonForm);

    // std::cout << std::endl;

    // std::cout << *shrubberyCreationForm << std::endl;
    // std::cout << *robotomyRequestForm << std::endl;
    // std::cout << *presidentialPardonForm << std::endl;
    // std::cout << std::endl;


    // std::cout << std::endl;
    std::cout << "---------------- vipBureaucrat ----------------" << std::endl;
    std::cout << std::endl;

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    try {
        shrubberyCreationForm->beSigned(vipBureaucrat);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        robotomyRequestForm->beSigned(vipBureaucrat);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        presidentialPardonForm->beSigned(vipBureaucrat);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    vipBureaucrat.signForm(shrubberyCreationForm->getSigned(), shrubberyCreationForm->getName());
    vipBureaucrat.signForm(robotomyRequestForm->getSigned(), robotomyRequestForm->getName());
    vipBureaucrat.signForm(presidentialPardonForm->getSigned(), presidentialPardonForm->getName());

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    vipBureaucrat.executeForm(*shrubberyCreationForm);
    vipBureaucrat.executeForm(*robotomyRequestForm);
    vipBureaucrat.executeForm(*presidentialPardonForm);

    shrubberyCreationForm->execute(vipBureaucrat);

    std::cout << std::endl;

    delete shrubberyCreationForm;
    delete robotomyRequestForm;
    delete presidentialPardonForm;


    hyojocho();
    return (0);
}