#include <iostream>
#include <string>
#include <vector>
#include <numeric>

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    if (begin(v) != end(v)) {
        os << *begin(v);
    }
    std::for_each(begin(v) + 1, end(v), [&os] (const T& i) {
        os << ", " << i;
    });
    return (os << " ]");
};

auto main() -> int {

    std::vector<int> v(10);
    std::iota(begin(v), end(v), 0);
    std::cout << v << std::endl;

    //std::rotate(begin(v), begin(v) + 4, end(v));

    auto f = find(begin(v), end(v), 5);
    //std::rotate(begin(v), f, f + 2);
    //std::rotate(begin(v) + 1, f, f + 2);
    //std::rotate(f + 1, f, f + 2); // CRASH
    std::rotate(f, f + 2, end(v) - 1);

    std::cout << v << std::endl;

    return 0;
}

