#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1("bureaucrat1", 150);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.decrementGrade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
    }   catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}