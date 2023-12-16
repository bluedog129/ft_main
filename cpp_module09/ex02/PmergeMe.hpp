#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <list>
#include <ctime>
#include <algorithm>

typedef std::vector<int> intVec;
typedef std::vector<std::pair<int, int> > pairVec;
typedef std::list<int> intList;
typedef std::list<std::pair<int, int> > pairList;

class PmergeMe {
private:
    PmergeMe(pairVec& init_data);
    PmergeMe(PmergeMe& other);

public:
    PmergeMe(void);
    ~PmergeMe(void);

    PmergeMe& operator=(const PmergeMe& other);

    // vector
    void vectorFordJohnson(int argc, char* argv[]);
    void inputToPairVector(pairVec& vector, int argc, char* argv[]);
    void inputToVector(intVec& vector, pairVec& pairVector, int size, char* numbers[]);
    void mergeVector(pairVec& vector);
    void mergeSort(pairVec& vector, int left, int right);
    void merge(pairVec& vector, int left, int middle, int right);
    void binaryInsertion(intVec& vector);
    size_t binarySearch(int target, intVec& result, int startIndex);
    size_t jacobsthal(size_t n);
    void insertion(intVec& result, int target, size_t insertIndex, pairVec& aIndexPos);
    void printPairVector(pairVec& vector);
    void printVector(intVec& vector);
    void applyOddFlag(intVec& result, intVec& vector, int oddFlag);

    // linked list
    void linkedListFordJohnson(int size, char* numbers[]);
    void inputToList(intList& list, int size, char* numbers[]);
    void preSortList(intList& list);
    void printList(intList& list);
    void makePairList(intList& list, pairList& pairList);
    void mergeList(intList& list);
    void mergePairList(pairList& list);
    void mergePart(pairList& pairs, pairList& left, pairList& right);
    void reSettingList(intList& list, pairList& pairList);
    void binaryInsertionList(intList& list, pairList& pairList);
    void printPairList(pairList& list);
};

#endif