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

    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

    delete rrf;
    hyojocho();
    return (0);
}