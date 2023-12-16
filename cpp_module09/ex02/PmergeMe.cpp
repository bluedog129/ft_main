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
    if (n == 0) return 1;
    if (n == 1) return 1;
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
    preSortList(list);
    mergeList(list);
    clock_t end = clock();
    std::cout << "Time to process a range of " << size << " elements with std::list : " << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

void PmergeMe::inputToList(intList& list, int size, char* numbers[]) {
    for (int i = 0; i < size; i++) {
        list.push_back(atoi(numbers[i]));
    }
}

void PmergeMe::preSortList(intList& list) {
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
}

// 여기서 부터 다시해야함
void PmergeMe::mergeList(intList& list) {
    pairList pairList;
    
    makePairList(list, pairList);
    mergePairList(pairList);
    binaryInsertionList(list, pairList);
    printList(list);
}

void PmergeMe::binaryInsertionList(intList& list, pairList& pair) {
    int oddFlag = 0;
    int lastElement = list.back();

    if (list.size() % 2 == 1) {
        oddFlag = 1;
    }
    list.clear();

    // 우선 list에 pair의 first 원소들을 삽입 -> mainElements 우선 삽입
    for (pairList::iterator it = pair.begin(); it != pair.end(); ++it) {
        list.push_back(it->first);
    }
    
    size_t i = 0; // Jacobsthal 함수에 전달할 인덱스
    while (!pair.empty()) {
    size_t jacobSize = jacobsthal(i); // Jacobsthal 수열의 i번째 값을 계산

        // Jacobsthal 수열의 길이만큼 pairList의 second 원소를 역순으로 삽입
        for (int j = jacobSize - 1; j >= 0 && !pair.empty(); --j) {
            pairList::iterator pairIt = pair.begin();
            advance(pairIt, j);

            int pendingElement = pairIt->second;
            intList::iterator pairFirstPos = find(list.begin(), list.end(), pairIt->first);
            
            // 이진 탐색을 사용하여 삽입할 위치를 찾는다
            intList::iterator insertPos = std::lower_bound(list.begin(), pairFirstPos, pendingElement);

            // pendingElement를 적절한 위치에 삽입한다
            list.insert(insertPos, pendingElement);

            // 다음 원소로 이터레이터를 이동시킨 후 현재 원소를 삭제한다
            pair.erase(pairIt);
        }
        i++; // Jacobsthal 수열의 다음 인덱스로 이동
    }

    if (oddFlag) {
        intList::iterator insertPos = std::lower_bound(list.begin(), list.end(), lastElement);
        list.insert(insertPos, lastElement);
    }
}

void PmergeMe::reSettingList(intList& list, pairList& pairList) {
    int oddFlag = 0;
    int lastElement = list.back();

    if (list.size() % 2 == 1) {
        oddFlag = 1;
    }

    list.clear();
    for (pairList::iterator it = pairList.begin(); it != pairList.end(); ++it) {
        list.push_back(it->first);
        list.push_back(it->second);
    }

    if (oddFlag) {
        list.push_back(lastElement);
    }
}

void PmergeMe::mergePairList(pairList& pairs) {
    if (pairs.size() <= 1) return; // Base case for recursion

    pairList leftHalf;
    pairList rightHalf;
    std::list<std::pair<int, int> >::iterator middle = std::next(pairs.begin(), pairs.size() / 2);

    leftHalf.splice(leftHalf.begin(), pairs, pairs.begin(), middle);
    rightHalf.splice(rightHalf.begin(), pairs, middle, pairs.end());

    // Recursively sort the two halves
    mergePairList(leftHalf);
    mergePairList(rightHalf);

    // Merge the sorted halves
    mergePart(pairs, leftHalf, rightHalf);
}

void PmergeMe::mergePart(pairList& pairs, pairList& left, pairList& right) {
    pairList::iterator leftIt = left.begin();
    pairList::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (leftIt->first < rightIt->first) {
            pairs.push_back(*leftIt);
            leftIt++;
        } else {
            pairs.push_back(*rightIt);
            rightIt++;
        }
    }

    pairs.splice(pairs.end(), left, leftIt, left.end());
    pairs.splice(pairs.end(), right, rightIt, right.end());
}


void PmergeMe::makePairList(intList& list, pairList& pairList) {
    for (intList::iterator it = list.begin(); it != list.end(); ) {
        if (std::next(it) == list.end())
            break;

        int first = *it;
        int second = *std::next(it);
        pairList.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
        
        std::advance(it, 2);
    }
}

void PmergeMe::printList(intList& list) {
    std::cout << "After  :";
    for (intList::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

void PmergeMe::printPairList(pairList& pairList) {
    std::cout << "Pair   :";
    for (pairList::iterator it = pairList.begin(); it != pairList.end(); ++it) {
        std::cout << " " << it->first << " " << it->second;
    }
    std::cout << std::endl;
}