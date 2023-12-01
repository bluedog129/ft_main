#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try {
        if (argc < 2) {
            throw std::invalid_argument("Usage: ./ex02 [number1] [number2] ...");
        }
        t_vec vector;

        PmergeMe pmergeMe;

        std::cout << "Before : ";
        for (int i = 1; i < argc; i++) {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;

        pmergeMe.vectorFordJohnson(vector, argc, argv);

        std::cout << "After : ";
        pmergeMe.printVector(vector);
        

    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}