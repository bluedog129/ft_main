#include "Array.hpp"

int main() {
    try {
        Array<int> intArr(5);
        for (unsigned int i = 0; i < intArr.size(); ++i) {
            intArr[i] = i + 1;
            std::cout << intArr[i] << " ";
        }
        std::cout << std::endl;

        Array<char> charArr(3);
        charArr[0] = 'a';
        charArr[1] = 'b';
        charArr[2] = 'c';

        for (unsigned int i = 0; i < charArr.size(); ++i) {
            std::cout << charArr[i] << " ";
        }
        std::cout << std::endl;

        Array<char> copyCharArr = charArr;
        for (unsigned int i = 0; i < copyCharArr.size(); ++i) {
            std::cout << copyCharArr[i] << " ";
        }
        std::cout << std::endl;

        // Test out of bounds
        std::cout << charArr[5] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}