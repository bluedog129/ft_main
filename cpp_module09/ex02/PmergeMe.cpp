#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int>& init_data) {
    _dataVector = init_data;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);

    
}

void PmergeMe::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void PmergeMe::sort() {
    mergeSort(_dataVector, 0, _dataVector.size() - 1);
}

void PmergeMe::printResult() const {
    for (int i = 0; i < static_cast<int>(_dataVector.size()); i++) {
        std::cout << _dataVector[i] << " ";
    }
    std::cout << std::endl;
}