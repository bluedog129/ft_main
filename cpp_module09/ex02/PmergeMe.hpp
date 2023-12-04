#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <deque>
#include <ctime>

typedef std::vector<int> intVec;
typedef std::vector<std::pair<int, int> > pairVec;
typedef std::deque<std::pair<int, int> > t_deque;

class PmergeMe {
private:
    
public:
    PmergeMe();
    PmergeMe(pairVec& init_data);
    PmergeMe(PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& other);

    void vectorFordJohnson(intVec& vector, int argc, char* argv[]);
    void inputToPairVector(pairVec& vector, int argc, char* argv[]);
    void inputToVector(intVec& vector, pairVec& pairVector);
    void mergeVector(pairVec& vector);
    void mergeSort(pairVec& vector, int left, int right);
    void merge(pairVec& vector, int left, int middle, int right);
    void binaryInsertion(intVec& vector);
    int jacobsthal(int n);
    void printPairVector(pairVec& vector);
    void printVector(intVec& vector);

    void listFordJohnson();
};

#endif