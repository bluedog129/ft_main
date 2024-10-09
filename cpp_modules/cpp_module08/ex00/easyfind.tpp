#include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(T const &container, int n) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end()) {
        throw std::out_of_range("Element not found in the container");
    }
    return it;
}