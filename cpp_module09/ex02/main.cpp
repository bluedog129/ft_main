#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try {
        if (argc < 2) {
            throw std::invalid_argument("Usage: ./ex02 [number1] [number2] ...");
        }
        t_vec inputVector;

        for (int i = 1; i < argc; ++i)
            inputVector.push_back(std::atoi(argv[i]));

        PmergeMe pmergeMe(inputVector);

        std::cout << "Before: ";
        for (std::vector<int>::size_type i = 0; i < inputVector.size(); ++i) {
            std::cout << inputVector[i] << " ";
        }
        std::cout << std::endl;

        pmergeMe.fordJohnsonSort(inputVector);

        std::cout << "After: ";
        pmergeMe.printResult(inputVector);

        std::cout << "Time to process a range of " << inputVector.size()
                  << " elements with std::vector : " << pmergeMe.getVectorSortTime() << " us" << std::endl;

        // std::cout << "Time to process a range of " << inputVector.size()
        //           << " elements with std::list : " << pmergeMe.getListSortTime() << " us" << std::endl;

    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}