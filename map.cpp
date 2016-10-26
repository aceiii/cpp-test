#include <iostream>
#include <string>
#include <vector>
#include <map>


template <typename K, typename V>
std::ostream& operator<< (std::ostream& os, const std::map<K,V>& m) {
    os << "{";
    auto it = begin(m);
    if (it != end(m)) {
        os << "{" << it->first << "," << it->second << "}";
    }
    it++;
    for (; it != end(m); it++) {
        os << ", {" << it->first << "," << it->second << "}";
    }
    return (os << "}");
}

auto main() -> int {

    std::map<int, int> m = {{1,2}, {2,3}, {4,5}};
    std::cout << m << std::endl;

    std::cout << m[7] << std::endl;

    m[10] = 123;

    std::cout << m[10] << std::endl;

    std::cout << m << std::endl;

    return 0;
}

