#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 8; i++)
        vec.push_back(i);
    std::list<int> lst;
    for (int i = 10; i < 20; i++)
        lst.push_back(i);

    try {
        std::cout << "Value 6 in vector : " << *easyfind(vec, 6) << std::endl;
        std::cout << "Value 12 in list : " << *easyfind(lst, 12) << std::endl;
        std::cout << "Value 42 in vector : " << *easyfind(vec, 42) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
