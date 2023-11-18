#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <list>
#include <ctime>

typedef std::vector<int> t_vec;
typedef std::list<int> t_list;

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
    void binaryInsertion(t_list& lst, int value);
    void printResult(t_vec& arr) const;
    double getVectorSortTime() const;
    double getListSortTime() const;
};

#endif