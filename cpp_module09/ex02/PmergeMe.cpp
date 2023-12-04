#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(pairVec& init_data) {
    for (pairVec::iterator it = init_data.begin(); it != init_data.end(); ++it) {
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

void PmergeMe::vectorFordJohnson(intVec& vector, int argc, char* argv[]) {
    pairVec pairVector;

    inputToPairVector(pairVector, argc - 1, argv);
    mergeVector(pairVector);
    inputToVector(vector, pairVector);
    binaryInsertion(vector);
}

void PmergeMe::binaryInsertion(intVec& vector) {
    intVec temp;
    pairVec pairVector;

    for (intVec::iterator it = vector.begin(); it != vector.end(); ++it) {
        std::pair<int, int> pair;
        pair.first = *it;
        
    }
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::inputToPairVector(pairVec& pairVector, int inputSize, char* argv[]) {
    for (int i = 0; i < inputSize / 2; i++)
    {
        std::pair<int, int> pair;
        pair.first = atoi(argv[i * 2 + 1]);
        pair.second = atoi(argv[i * 2 + 2]);
        pairVector.push_back(pair);
    }
    if (inputSize % 2 != 0) {
        std::pair<int, int> pair;
        pair.first = atoi(argv[inputSize]);
        pair.second = -1;
        pairVector.push_back(pair);
    }
}

void PmergeMe::inputToVector(intVec& vector, pairVec& pairVector) {
    for (pairVec::iterator it = pairVector.begin(); it != pairVector.end(); ++it) {
        vector.push_back(it->first);
        if (it->second != -1) {
            vector.push_back(it->second);
        }
    }
}

void PmergeMe::mergeVector(pairVec& pairVector) {
    for (pairVec::iterator it = pairVector.begin(); it != pairVector.end(); ++it) {
        if (it->first < it->second) {
            std::swap(it->first, it->second);
        }
    }
    mergeSort(pairVector, 0, pairVector.size() - 1);
}

void PmergeMe::mergeSort(pairVec& pairVector, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(pairVector, left, middle);
        mergeSort(pairVector, middle + 1, right);
        merge(pairVector, left, middle, right);
    }
}

void PmergeMe::merge(pairVec& pairVector, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 벡터 생성
    pairVec L, R;
    L.reserve(n1);
    R.reserve(n2);

    // 데이터 복사
    for (int i = 0; i < n1; ++i)
        L.push_back(pairVector[left + i]);
    for (int j = 0; j < n2; ++j)
        R.push_back(pairVector[middle + 1 + j]);

    // 병합
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            pairVector[k] = L[i];
            ++i;
        } else {
            pairVector[k] = R[j];
            ++j;
        }
        ++k;
    }

    // 나머지 요소들 복사
    while (i < n1) {
        pairVector[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        pairVector[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::printPairVector(pairVec& pairVector) {
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it) {
       std::cout << " " << it->first << " " << it->second;
    }
    std::cout << std::endl;
}

void PmergeMe::printVector(intVec& vector) {
    for (intVec::iterator it = vector.begin(); it != vector.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}
