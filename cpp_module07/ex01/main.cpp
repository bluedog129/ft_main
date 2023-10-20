#include "iter.hpp"

int main(void)
{
    // non-const
    int int_array[] = {1, 2, 3, 4, 5};
    char str_array[] = {'a', 'b', 'c'};

    std::cout << "< before increment >" << std::endl << std::endl;
    std::cout << "int_array:" << std::endl;
    iter(int_array, 5, print);
    std::cout << std::endl;

    std::cout << "str_array:" << std::endl;
    iter(str_array, 3, print);
    std::cout << std::endl << std::endl;

    // increment
    iter(int_array, 5, increment);
    iter(str_array, 3, increment);

    std::cout << "< after increment >" << std::endl << std::endl;
    std::cout << "int_array:" << std::endl;
    iter(int_array, 5, print);
    std::cout << std::endl;

    std::cout << "char_array:" << std::endl;
    iter(str_array, 3, print);
    std::cout << std::endl;

    // const
    const char const_str_array[] = {'A', 'B', 'C'};
    const int const_int_array[] = {1, 2, 3};
    std::cout << "const_str_array:" << std::endl;
    iter(const_str_array, 3, print);
    std::cout << std::endl;
    std::cout << "const_int_array:" << std::endl;
    iter(const_int_array, 3, print);
    std::cout << std::endl;

    return 0;
}
