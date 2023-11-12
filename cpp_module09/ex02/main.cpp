#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    t_vec inputVector;
    t_list inputList;

    for (int i = 1; i < argc; ++i) {
        inputVector.push_back(std::atoi(argv[i]));
    }

    PmergeMe pmergeMe(inputVector);

    // 정렬 전 숫자들을 출력합니다.
    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < inputVector.size(); ++i) {
        std::cout << inputVector[i] << " ";
    }
    std::cout << std::endl;

    // 병합정렬을 수행합니다.
    pmergeMe.fordJohnsonMergeSort(inputVector);
    // 삽입정렬을 수행합니다.
    // pmergeMe.fordJohnsonInsertionSort(inputList);

    // 정렬된 결과를 출력합니다.
    std::cout << "After: ";
    pmergeMe.printResult(inputVector);

    return 0;
}