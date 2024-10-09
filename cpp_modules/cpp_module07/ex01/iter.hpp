#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <ostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    std::cout << "non-const iter called" << std::endl;
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    std::cout << "const iter called" << std::endl;
}

template <typename T>
void print(T &element)
{
    std::cout << element << std::endl;
}

template <typename T>
void increment(T &element)
{
    element++;
}

#endif