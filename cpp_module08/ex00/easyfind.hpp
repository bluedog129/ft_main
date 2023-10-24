#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
typename T::const_iterator easyfind(T const &container, int n);

#include "easyfind.tpp"

#endif