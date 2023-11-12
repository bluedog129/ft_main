#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int>& init_data) {
    _arrVector = init_data;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    _arrVector = other._arrVector;
    _arrList = other._arrList;
    _results = other._results;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fordJohnsonMergeSort(t_vec& arrVector) {
    // exit
    if (arrVector.size() == 1) {
        return;
    }
    for (size_t i = 0; i < arrVector.size() - 1; i += 2) {
        if (arrVector[i] < arrVector[i + 1]) {
            int temp = arrVector[i];
            arrVector[i] = arrVector[i + 1];
            arrVector[i + 1] = temp;
        }
    }
    // create arrForA
    t_vec arrForA;
    for (size_t i = 0; i < arrVector.size() - 1; i += 2) {
        arrForA.push_back(arrVector[i]);
    }
    
    if (arrForA.size() > 1) {
        fordJohnsonMergeSort(arrForA);
    }

    // Simple insertion sort for arrForA
    for (size_t i = 1; i < arrForA.size(); i++) {
        int key = arrForA[i];
        int j = i - 1;

        // Move elements of arrForA[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arrForA[j] > key) {
            arrForA[j + 1] = arrForA[j];
            j = j - 1;
        }
        arrForA[j + 1] = key;
    }

    // Update the even-index elements of arrVector with sorted arrForA
    for (size_t i = 0, j = 0; i < arrVector.size() && j < arrForA.size(); i += 2, j++) {
        arrVector[i] = arrForA[j];
    }
}

// void PmergeMe::fordJohnsonInsertionSort(t_list& list) {
// }

void PmergeMe::printResult(t_vec& arr) const {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}