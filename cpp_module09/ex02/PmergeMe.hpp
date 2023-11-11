#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <deque>

class PmergeMe {
private:
    std::vector<int> _dataVector;
    std::deque<int> _dataDeque;
    std::string _results;

public:
    PmergeMe();
    PmergeMe(std::vector<int>& init_data);
    // PmergeMe(PmergeMe& other);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& other);

    void sort();
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void mergeSort(std::vector<int>& arr, int left, int right);
    // void insertionSort();
    // void setInput(const std::vector<int>& input);
    // void printError() const;
    void printResult() const;
};

#endif