#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

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

auto test1() -> void {
    std::map<int, int> m = {{1,2}, {2,3}, {4,5}};
    std::cout << m << std::endl;

    std::cout << m[7] << std::endl;

    m[10] = 123;

    std::cout << m[10] << std::endl;

    std::cout << m << std::endl;
}

auto test2() -> void {
    std::map<std::string, std::string> m;
    m["a"] = "first";
    m["z"] = "second";

    std::cout << m << std::endl;

    m["r"] = "third";

    std::cout << m << std::endl;
}

auto test2() -> void {
    std::map<std::string, std::string> m;
    m["a"] = "first";
    m["z"] = "second";

    std::cout << m << std::endl;

    m["r"] = "third";

    std::cout << m << std::endl;
}

auto main() -> int {
    test2();
    return 0;
}
