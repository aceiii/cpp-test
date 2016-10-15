#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

template <typename T>
void print(const T& container) {
    std::for_each(begin(container), end(container), [](auto& i) {
        std::cout << i << std::endl;
    });
}

template <typename T, template <typename...> class V>
std::ostream& operator<< (std::ostream& os, const V<T>& t) {
    os << "[ ";
    if (t.size()) {
        os << *begin(t);
        std::for_each(begin(t) + 1, end(t), [&](auto& i) {
            os << ", " << i;
        });
        os << " ]";
    }
    return os;
}

template <typename T, typename = std::enable_if<std::is_array<T>>
std::ostream& operator<< (std::ostream& os, T arr) {
    return os;
}

auto operator<< (std::ostream& os, const std::string& s) -> std::ostream& {
    return (os << s.c_str());
}

template <typename T>
auto print_info(const T& t) -> void {
    std::cout << "type: " << typeid(t).name() << std::endl;
    std::cout << "value: " << t << std::endl;
}

auto main() -> int {
    auto a = std::vector<int> { 1,2,3,4 };
    auto b = {1,2,3,4,5};
    auto c = "alsdjf";
    auto d = R"(helloworld)";
    std::string e {"hello wtf" };
    int f[] {14,5,6};

    print_info(a);
    print_info(b);
    print_info(c);
    print_info(d);
    print_info(e);
    print_info(f);

    return 0;
}


