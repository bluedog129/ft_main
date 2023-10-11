#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucratJohn("BureaucratJohn", 43);
        std::cout << bureaucratJohn << std::endl;
        Form formForJohn("FormForJohn", 42, 42);
        std::cout << formForJohn << std::endl;
        bureaucratJohn.decrementGrade();
        bureaucratJohn.signForm(formForJohn);
        std::cout << std::endl;
        bureaucratJohn.incrementGrade();
        bureaucratJohn.incrementGrade();
        bureaucratJohn.signForm(formForJohn);
        std::cout << formForJohn << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}