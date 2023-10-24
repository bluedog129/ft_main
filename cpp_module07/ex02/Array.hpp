#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T*              _array;
    unsigned int    _size;
public:
    Array();
    Array(unsigned int n);
    Array(Array const & other);
    ~Array();

    Array & operator=(Array const & other);

    T & operator[](long i);
    const T & operator[](long i) const;
    unsigned int size() const;

    class execption : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Out of bounds";
        }
    };
};

#include "Array.tpp"

#endif