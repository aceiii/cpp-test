#include <iostream>
#include <vector>
#include <string>
#include <functional>

template <typename T, typename C>
void for_each(const C& container, std::function<void(const T&)> func) {
    for (auto it = begin(container); it != end(container); it++) {
        //func(std::forward(*it));
        func(*it);
    }
}

/*template <typename T, typename F>
void for_each(const std::vector<T>& v, F func) {
    for (auto it = begin(v); it != end(v); it++) {
        //func(std::forward(*it));
        func(*it);
    }
}*/

/*template <typename T>
void print(const T& t) {
    std::cout << t << std::endl;
}*/

void print(int i) {
    std::cout << i << std::endl;
}


using namespace std::placeholders;

auto main() -> int {
    std::vector<int> a = { 1, 2, 3, 5, 99 };

    /*for_each(a, [] (const int& i) {
        std::cout << i << std::endl;
    });*/

    //for_each(a, std::bind(print, _1));

    std::function<void(const int&)> my_func;

    my_func = print;

    if (my_func) {
        my_func(123);
    }

    for_each(a, print);

    return 0;
}

