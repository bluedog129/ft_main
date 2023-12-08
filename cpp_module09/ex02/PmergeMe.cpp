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

void PmergeMe::vectorFordJohnson(int size, char* numbers[]) {
    intVec vector;
    pairVec pairVector;

    clock_t start = clock();
    inputToPairVector(pairVector, size, numbers);
    mergeVector(pairVector);
    inputToVector(vector, pairVector, size, numbers);
    binaryInsertion(vector);
    clock_t end = clock();
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

void PmergeMe::binaryInsertion(intVec& vector) {
    intVec result;
    intVec pendingElements;
    pairVec aIndexPos;
    int oddFlag = 0;

    if (vector.size() % 2 == 1) {
        oddFlag = 1;
    }
    for (size_t i = 0; i < vector.size() / 2; i++) {
        result.push_back(vector[i * 2]);
        pendingElements.push_back(vector[i * 2 + 1]);
        aIndexPos.push_back(std::make_pair(vector[i * 2], i));
    }

    insertion(result, pendingElements[0], 0, aIndexPos); // 첫번째 pendingElements 원소 삽입
    pendingElements.erase(pendingElements.begin()); // pendingElements의 첫번째 원소 삭제
    aIndexPos.erase(aIndexPos.begin()); // aIndexPos의 첫번째 원소 삭제
    // aIndexPos의 인덱스 정보 갱신
    for (size_t i = 0; i < aIndexPos.size(); ++i) {
        aIndexPos[i].second++;
    }
    size_t i = 1;  // Jacobsthal 함수에 전달할 인덱스
    while (pendingElements.size() != 0) {
        size_t jacobSize = jacobsthal(i);
        intVec insertVector;

        // Jacobsthal 수에 따라 insertVector 채우기
        for (size_t j = 0; j < jacobSize && j < pendingElements.size(); j++) {
            insertVector.push_back(pendingElements[j]);
        }
        // insertVector를 result에 삽입
        for (int j = insertVector.size() - 1; j >= 0; --j) {
            size_t resultInsertIndex = binarySearch(insertVector[j], result, aIndexPos[j].second);
            insertion(result, insertVector[j], resultInsertIndex, aIndexPos);
        }  

        // 삽입된 원소 및 위치 정보 삭제
        pendingElements.erase(pendingElements.begin(), pendingElements.begin() + insertVector.size());
        aIndexPos.erase(aIndexPos.begin(), aIndexPos.begin() + insertVector.size());

        i++;
    }
    applyOddFlag(result, vector, oddFlag);
    printVector(result);
}

void PmergeMe::applyOddFlag(intVec& result, intVec& vector, int oddFlag) {
    if (oddFlag)
    {
        int lastElement = vector.back();

        if (result.back() <= lastElement) {
            result.push_back(lastElement);
        } else {
            for (size_t i = 0; i < result.size(); i++) {
                if (result[i] > lastElement) {
                    result.insert(result.begin() + i, lastElement);
                    break;
                }
            }
        }
    }
}

size_t PmergeMe::binarySearch(int target, intVec& result, int endIndex) {
    size_t left = 0;
    size_t right = endIndex; // 끝 인덱스로 초기화

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (result[mid] < target) {
            left = mid + 1; // 타겟 값이 중간값보다 크면, 왼쪽 범위를 조정
        } else {
            right = mid; // 타겟 값이 중간값보다 작거나 같으면, 오른쪽 범위를 조정
        }
    }

    return left; // 삽입할 위치 반환
}

void PmergeMe::insertion(intVec& result, int target, size_t insertIndex, pairVec& aIndexPos) {
    int elementToInsert = target;
    result.insert(result.begin() + insertIndex, elementToInsert);

    for (size_t i = 0; i < aIndexPos.size(); ++i) {
        if ((size_t)aIndexPos[i].second >= insertIndex) {
            aIndexPos[i].second++;
        }
    }
}

size_t PmergeMe::jacobsthal(size_t n) {
    if (n == 0) return 2;
    if (n == 1) return 2;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::inputToPairVector(pairVec& pairVector, int inputSize, char* argv[]) {
    for (int i = 0; i < inputSize / 2; i++) {
        std::pair<int, int> pair;
        pair.first = atoi(argv[i * 2]);
        pair.second = atoi(argv[i * 2 + 1]);
        pairVector.push_back(pair);
    }
}

void PmergeMe::inputToVector(intVec& vector, pairVec& pairVector, int size, char* numbers[]) {
    for (pairVec::iterator it = pairVector.begin(); it != pairVector.end(); ++it) {
        vector.push_back(it->first);
        vector.push_back(it->second);
    }
    if (size & 1)
        vector.push_back(atoi(numbers[size - 1]));
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
    std::cout << "After  :";
    for (intVec::iterator it = vector.begin(); it != vector.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

// linked list
void PmergeMe::linkedListFordJohnson(int size, char* numbers[]) {
    intList list;

    clock_t start = clock();
    inputToList(list, size, numbers);
    mergeList(list);
    clock_t end = clock();
    std::cout << "Time to process a range of " << size << " elements with std::list : " << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

void PmergeMe::inputToList(intList& list, int size, char* numbers[]) {
    for (int i = 0; i < size; i++) {
        list.push_back(atoi(numbers[i]));
    }
}

void PmergeMe::mergeList(intList& list) {
    for (intList::iterator it = list.begin(); it != list.end(); ) {
        // 마지막 원소인 경우에는 반복문을 종료
        if (std::next(it) == list.end()) break;

        int first = *it;
        int second = *std::next(it);

        // 첫 번째 원소가 두 번째 원소보다 작은 경우 위치 교환
        if (first < second) {
            *it = second;
            *std::next(it) = first;
        }

        // 두 원소를 건너뛰기
        std::advance(it, 2);
    }

    for (intList::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}