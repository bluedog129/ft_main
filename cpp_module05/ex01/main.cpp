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
        // formForJohn.beSigned(bureaucratJohn);
        // bureaucratJohn.signForm(formForJohn.getSigned(), formForJohn.getName());
        bureaucratJohn.incrementGrade();
        bureaucratJohn.incrementGrade();
        std::cout << bureaucratJohn << std::endl;
        formForJohn.beSigned(bureaucratJohn);
        std::cout << formForJohn << std::endl;
        bureaucratJohn.signForm(formForJohn.getSigned(), formForJohn.getName());
        std::cout << formForJohn << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}