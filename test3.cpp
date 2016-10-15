#include <iostream>
#include <vector>


int func() {
    return 1;
}


asdf<T> foo() {
}

auto func1() -> decltype(foo()) {
    auto f = foo();

    return f;
}

template <typename T>
void blah(T t) {
    ...
}

template <const char*>
void blah(const char* t) {
    ...
}


auto main() -> int {

    std::vector<int> v = {1, 2, 3};
    std::vector<int> v1([1,2,3]);
    // vector<int> v = new vector<int>();

    // IList<int> list = new List<int>();
    // list.sort();


    sort(v.begin(), v.end());
    sort(begin(v), end(v));


    std::vector<int> v3 = {3,4,5,6,123,9,10};
    std::vector<int>::iteterator item = find(begin(v), end(v), 123);

    auto item = find(begin(v), end(v), 123);
    if (item != end(v)) {
        std::cout << "Found" << std::endl;
    }

    blah("alsdjf");
    blah(123);

    return 0;
}


