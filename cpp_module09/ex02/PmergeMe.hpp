#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <list>

typedef std::vector<int> t_vec;
typedef std::list<int> t_list;

class PmergeMe {
private:

    t_vec _arrVector;
    t_list _arrList;
    std::string _results;

public:
    PmergeMe();
    PmergeMe(t_vec& init_data);
    PmergeMe(PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& other);

    void fordJohnsonMergeSort(t_vec& arr);
    void fordJohnsonInsertionSort(t_list& arr);
    void printResult(t_vec& arr) const;
};

#endif