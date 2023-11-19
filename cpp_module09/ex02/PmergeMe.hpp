#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <deque>
#include <ctime>

typedef std::vector<int> t_vec;
typedef std::deque<int> t_deque;

class PmergeMe {
private:
    t_vec _arrVector;
    double _vectorSortTime;
    double _listSortTime;

public:
    PmergeMe();
    PmergeMe(t_vec& init_data);
    PmergeMe(PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& other);

    void fordJohnsonSort(t_vec& arr);
    void mergeSort(t_vec& mainChain);
    t_vec merge(const t_vec& left, const t_vec& right);
    void binaryInsertion(t_deque& lst, int value);
    void printResult(t_vec& arr) const;
    double getVectorSortTime() const;
    double getListSortTime() const;
};

#endif