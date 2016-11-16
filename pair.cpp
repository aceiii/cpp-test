#include <iostream>
#include <string>
#include <vector>
#include <utility>

auto main() -> int {

    auto pair1 = std::make_pair(1, 2);
    auto pair2 = std::make_pair(1, 2);
    auto pair3 = std::make_pair(2, 3);

    std::cout << std::boolalpha << (pair1 == pair2) << std::endl;
    std::cout << std::boolalpha << (pair2 == pair3) << std::endl;

    return 0;
}
