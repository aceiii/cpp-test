#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#include "print.hpp"

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

    std::vector<int> v1(5);
    std::iota(begin(v1), end(v1), 101);
    std::cout << "v1 before: " << v1 << std::endl;

    std::rotate(begin(v1), next(begin(v1)), end(v1));
    std::cout << "v1 after:  " << v1 << std::endl;

    std::rotate(begin(v1), next(begin(v1)), end(v1));
    std::cout << "v1 again:  " << v1 << std::endl;

    std::vector<int> v2(4);
    std::iota(begin(v2), end(v2), 200);
    std::cout << "v2 before: " << v2 << std::endl;

    std::rotate(begin(v2), next(begin(v2)), end(v2));
    std::cout << "v2 after:  " << v2 << std::endl;

    int a[4];
    std::iota(std::begin(a), std::end(a), 1);
    std::rotate(std::begin(a), std::next(std::begin(a)), std::end(a));
    std::cout << "a: " << print(std::begin(a), std::end(a)) << std::endl;

    return 0;
}

