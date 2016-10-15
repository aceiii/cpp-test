#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>


template <typename T>
auto operator<< (std::ostream& os, const std::vector<T>& v) -> std::ostream& {
    os << "[ ";
    if (!v.empty()) {
        os << (*begin(v));
        std::for_each(begin(v) + 1, end(v), [&](auto& i) {
            os << ", " << i;
        });
    }
    return (os << " ]");
}

auto create_random_ints(int n) -> std::vector<int> {

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(1, 49);

    std::vector<int> v(n);
    for (int i = 0; i < n; i += 1) {
        v[i] = dist(generator);
    }

    return v;
}

template <typename T>
void random_shuffle(std::vector<T>& v) {
    std::random_device rd;
    std::mt19937 generator(rd());
    shuffle(begin(v), end(v), generator);
}

auto main() -> int {

    auto r = create_random_ints(6);
    std::cout << r << std::endl;

    sort(begin(r), end(r));
    std::cout << r << std::endl;

    random_shuffle(r);
    std::cout <<  r << std::endl;

    random_shuffle(r);
    std::cout <<  r << std::endl;

    return 0;
}


