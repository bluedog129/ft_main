#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void hyojocho()
{
    system("leaks ex03");
}

int main()
{
    Intern someRandomIntern;
    AForm* rrf;

    std::cout << std::endl;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    std::cout << std::endl;
    rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
    std::cout << std::endl;
    rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
    std::cout << std::endl;

    delete rrf;
    std::cout << std::endl;
    hyojocho();
    return (0);
}