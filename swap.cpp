#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

template <typename T>
auto operator<< (std::ostream& os, const std::vector<T>& v) -> std::ostream& {
    os << "[ ";
    if (v.size()) {
        os << *(begin(v));
        std::for_each(begin(v) + 1, end(v), [&] (const T& i) {
            os << ", " << i;
        });
    }
    return (os << " ]");
}

auto main() -> int {

    std::vector<int> a {1,2,3};

    std::swap(a[0], a[1]);


    std::cout << a << std::endl;

    return 0;
}


