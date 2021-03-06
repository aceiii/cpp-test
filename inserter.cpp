#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iterator>

#include "print.hpp"

auto main() -> int {

    std::vector<int> v1 = { 1, 2, 5, 42, 6, 7, 99 };
    std::cout << "v1: " <<  v1 << std::endl;

    auto v2 = v1;
    v2.push_back(234);
    std::cout << "v1: " <<  v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;

    auto v3 { v2 };
    v3.push_back(1923);
    std::cout << "v2: " << v3 << std::endl;
    std::cout << "v3: " << v3 << std::endl;

    std::vector<int> v4;
    std::cout << "v4 before: " << v4 << std::endl;

    copy(begin(v3), end(v3), std::back_inserter(v4));
    std::cout << "v4 after:  " << v4 << std::endl;

    std::vector<int> v5 (v3.size() + 2);
    copy(begin(v3), end(v3), begin(v5) + 1);
    std::cout << "v5: " << v5 << std::endl;

    std::vector<int> v6(10);
    std::iota(begin(v6), end(v6), 100);
    std::cout << "v6 before: " << v6 << std::endl;

    copy(begin(v3), end(v3), std::inserter(v6, next(begin(v6))));
    std::cout << "v6 after:  " << v6 << std::endl;

    std::vector<int> v7(16);
    std::iota(begin(v7), end(v7), 934);

    int a[16];
    std::fill(std::begin(a), std::end(a), 9);
    std::cout << "a: " << print(std::begin(a), std::end(a)) << std::endl;

    std::copy(begin(v7), end(v7), std::begin(a));
    std::cout << "a: " << print(std::begin(a), std::end(a)) << std::endl;

    return 0;
}

