#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n), _vec(other._vec) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_vec.size() >= _n)
        throw NoSpaceException();
    _vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_vec.size() + std::distance(begin, end) > _n)
        throw NoSpaceException();
    _vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan() const {
    if (_vec.size() <= 1)
        throw NoSpanException();
    std::vector<int> tmp(_vec);
    std::sort(tmp.begin(), tmp.end());

    int min = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it) {
        if (*(it + 1) - *it < min)
            min = *(it + 1) - *it;
    }
    return min;
}

int Span::longestSpan() const {
    if (_vec.size() <= 1)
        throw NoSpanException();
    std::vector<int> tmp(_vec);
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

const char *Span::NoSpanException::what() const throw() {
    return "No span to find";
}

const char *Span::NoSpaceException::what() const throw() {
    return "No space left";
}