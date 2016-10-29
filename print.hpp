#ifndef __PRINT_HPP__
#define __PRINT_HPP__

#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    auto it = std::begin(v);
    if (it != std::end(v)) {
        os << *it;
        while (++it != std::end(v)) {
            os << ", " << *it;
        }
    }
    return (os << " ]");
}

template <typename It>
struct print_list_t {
    It begin, end;
};

template <typename It>
print_list_t<It> print(It begin, It end) {
    return print_list_t<It>{ begin, end };
}

template <typename It>
std::ostream& operator << (std::ostream& os, const print_list_t<It>& pl) {
    os << "[ ";
    It it = pl.begin;
    if (it != pl.end) {
        os << *it;
        while (++it != pl.end) {
            os << ", " << *it;
        }
    }
    return (os << " ]");
}

#endif//__PRINT_HPP__
