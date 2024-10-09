#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _vec;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();

        Span &operator=(const Span &other);

        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan() const;
        int longestSpan() const;

        class NoSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NoSpaceException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif