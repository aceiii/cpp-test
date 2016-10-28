#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct is_digit_predicate {
    bool operator () (const unsigned char& b) const {
        return isdigit(b);
    }
};

struct is_ascii_predicate {
    bool operator() (const unsigned char& b) const {
        return b
    }
};

int main() {
    using namespace std::string_literals;

    std::string s = "9043820394820a34"s;
    std::string s = "nOWTHATTHEPARTYISJUMPING*"s;

    //auto pred = [] (unsigned char c) { return isdigit(c); };
    auto pred = is_digit_predicate();

    std::cout << std::boolalpha << std::all_of(begin(s), end(s), pred) << std::endl;

    return 0;
}

