#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(t_vec& init_data) {
    for (t_vec::iterator it = init_data.begin(); it != init_data.end(); ++it) {
        std::cout << " " << it->first << " " << it->second;
    }
    std::cout << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        // copy
    }
    return *this;
}

PmergeMe::PmergeMe(PmergeMe& other) {
    *this = other;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::vectorFordJohnson(t_vec& vector, int argc, char* argv[]) {
    inputToVector(vector, argc - 1, argv);
    mergeVector(vector);
    binaryInsertion(vector);
}

void PmergeMe::binaryInsertion(t_vec& vector) {

}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::inputToVector(t_vec& vector, int inputSize, char* argv[]) {
    for (int i = 0; i < inputSize / 2; i++)
    {
        std::pair<int, int> pair;
        pair.first = atoi(argv[i * 2 + 1]);
        pair.second = atoi(argv[i * 2 + 2]);
        vector.push_back(pair);
    }
    if (inputSize % 2 != 0) {
        std::pair<int, int> pair;
        pair.first = atoi(argv[inputSize]);
        pair.second = -1;
        vector.push_back(pair);
    }
}

void PmergeMe::mergeVector(t_vec& vector) {
    for (t_vec::iterator it = vector.begin(); it != vector.end(); ++it) {
        if (it->first < it->second) {
            std::swap(it->first, it->second);
        }
    }
    mergeSort(vector, 0, vector.size() - 1);
}

void PmergeMe::mergeSort(t_vec& vector, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(vector, left, middle);
        mergeSort(vector, middle + 1, right);
        merge(vector, left, middle, right);
    }
}

void PmergeMe::merge(t_vec& vector, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 벡터 생성
    t_vec L, R;
    L.reserve(n1);
    R.reserve(n2);

    // 데이터 복사
    for (int i = 0; i < n1; ++i)
        L.push_back(vector[left + i]);
    for (int j = 0; j < n2; ++j)
        R.push_back(vector[middle + 1 + j]);

    // 병합
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            vector[k] = L[i];
            ++i;
        } else {
            vector[k] = R[j];
            ++j;
        }
        ++k;
    }

    // 나머지 요소들 복사
    while (i < n1) {
        vector[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        vector[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::printVector(t_vec& vector) {
    for (std::vector<std::pair<int, int> >::iterator it = vector.begin(); it != vector.end(); ++it) {
       std::cout << " " << it->first << " " << it->second;
    }
    std::cout << std::endl;
}
