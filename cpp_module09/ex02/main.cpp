#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        input.push_back(std::atoi(argv[i]));
    }

    PmergeMe pmergeMe(input);

    // 정렬 전 숫자들을 출력합니다.
    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < input.size(); ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;

    // 정렬을 수행합니다.
    pmergeMe.sort();

    // 정렬된 결과를 출력합니다.
    std::cout << "After: ";
    pmergeMe.printResult();

    return 0;
}