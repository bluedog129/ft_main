#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int>& init_data) {
    _arrVector = init_data;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _arrVector = other._arrVector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void checkElements(t_vec& arr, std::string name) {
    std::cout << name << " : ";
    for (size_t i = 0; i < arr.size() - 1; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fordJohnsonSort(t_vec& arr) {
    t_vec mainChain, pendingElements;

    for (size_t i = 0; i <= arr.size() / 2; i++) {
        mainChain.push_back(std::max(arr[i * 2], arr[i * 2 + 1]));
        pendingElements.push_back(std::min(arr[i * 2], arr[i * 2 + 1]));
    }

    if (arr.size() % 2 != 0) {
        pendingElements.push_back(arr[arr.size() - 1]);
    }

    mergeSort(mainChain);

    checkElements(mainChain, "mainChain");
    checkElements(pendingElements, "pendingElements");

    // t_deque mergedChain(mainChain.begin(), mainChain.end());

    // if (!pendingElements.empty()) {
    //     mergedChain.push_front(pendingElements[0]);
    // }

    // for (int i = pendingElements.size() - 1; i > 0; i--) {
    //     binaryInsertion(mergedChain, pendingElements[i]);
    // }

    // arr.assign(mergedChain.begin(), mergedChain.end());
}

void PmergeMe::mergeSort(t_vec& mainChain) {
    if (mainChain.size() <= 1) {
        return;
    }

    t_vec left, right;

    for (size_t i = 0; i < mainChain.size() / 2; i++) {
        left.push_back(mainChain[i]);
    }

    for (size_t i = mainChain.size() / 2; i < mainChain.size(); i++) {
        right.push_back(mainChain[i]);
    }

    mergeSort(left);
    mergeSort(right);

    mainChain = merge(left, right);
}

t_vec PmergeMe::merge(const t_vec& left, const t_vec& right) {
    t_vec result;

    size_t leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

void PmergeMe::binaryInsertion(t_deque& sortedArray, int value) {
    // std::lower_bound 함수는 C++98 표준에 포함되어 있다.
    t_deque::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), value);
    sortedArray.insert(it, value);
}

void PmergeMe::printResult(t_vec& arr) const {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::getVectorSortTime() const {
    return _vectorSortTime;
}

double PmergeMe::getListSortTime() const {
    return _listSortTime;
}