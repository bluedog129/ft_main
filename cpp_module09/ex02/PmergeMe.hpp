#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <deque>
#include <ctime>

typedef std::vector<std::pair<int, int> > t_vec;
typedef std::deque<std::pair<int, int> > t_deque;

class PmergeMe {
private:
    
public:
    PmergeMe();
    PmergeMe(t_vec& init_data);
    PmergeMe(PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& other);

    void vectorFordJohnson(t_vec& vector, int argc, char* argv[]);
    void inputToVector(t_vec& vector, int argc, char* argv[]);
    void mergeVector(t_vec& vector);
    void mergeSort(t_vec& vector, int left, int right);
    void merge(t_vec& vector, int left, int middle, int right);
    void printVector(t_vec& vector);

    void listFordJohnson();
};

#endif