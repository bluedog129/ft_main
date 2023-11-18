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

void PmergeMe::fordJohnsonSort(t_vec& arr) {
    if (arr.size() <= 1) {
        return ;
    }

    clock_t startVector = clock();
    t_vec a, b;

    for (size_t i = 0; i < arr.size() / 2; ++i) {
        a.push_back(std::max(arr[i * 2], arr[i * 2 + 1]));
        b.push_back(std::min(arr[i * 2], arr[i * 2 + 1]));
    }
    if (arr.size() % 2 == 1) {
        a.push_back(arr.back());
    }

    fordJohnsonSort(a);

    clock_t endVector = clock();
    _vectorSortTime = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

    // Convert vector 'b' to list 'b_list' for binary insertion sort
    t_list b_list(b.begin(), b.end());

    // Step 3: Insertion using binaryInsertion on the list
    for (t_list::iterator it = b_list.begin(); it != b_list.end(); ++it) {
        binaryInsertion(b_list, *it);
    }

    // Merge the two halves back into the vector 'arr'
    // Clear 'arr' and then merge the sorted halves
    arr.clear();
    std::copy(a.begin(), a.end(), std::back_inserter(arr)); // Add sorted 'a' half
    std::copy(b_list.begin(), b_list.end(), std::back_inserter(arr)); // Merge in sorted 'b_list' half
}

void PmergeMe::binaryInsertion(t_list& lst, int value) {
    // The iterator to track the insertion point
    t_list::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it) {
        if (*it > value) {
            break; // Found the insertion point
        }
    }
    lst.insert(it, value); // Insert before the element that is greater than the value
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