#include "PmergeMe.hpp"
#include <set>

void validateArgs(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++) {
        std::string arg = argv[i];

        // 문자열을 int로 변환
        char* end;
        long value = std::strtol(arg.c_str(), &end, 10);

        // 변환 오류 또는 범위 초과 검사
        if (*end != '\0' || value < INT_MIN || value > INT_MAX || value == 0) {
            throw std::invalid_argument("Argument is invalid or out of int range: " + arg);
        }

        // 중복 값 검사는 수행하지 않음
    }
}

int main(int argc, char* argv[])
{
    try {
        if (argc < 2) {
            throw std::invalid_argument("Usage: ./ex02 [number1] [number2] ...");
        }

        validateArgs(argc - 1, argv + 1);

        PmergeMe pmergeMe;

        std::cout << "Before : ";
        for (int i = 1; i < argc; i++) {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;

        pmergeMe.vectorFordJohnson(argc - 1, argv + 1);
        pmergeMe.linkedListFordJohnson(argc - 1, argv + 1);
        
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}