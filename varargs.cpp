#include <iostream>
#include <vector>
#include <cstdarg>

int add_nums(int count, ...) {
    int result = 0;

    va_list vargs;
    va_start(vargs, count);
    for (int i = 0; i < count; i += 1) {
        result += va_arg(vargs, int);
    }
    va_end(vargs);

    return result;
}

int main(int argc, char *argv[]) {
    std::cout << add_nums(2, 2, 3) << std::endl;
    std::cout << add_nums(2, "2", 3.0) << std::endl;
    std::cout << add_nums(2, 3.0, 5.6) << std::endl;
    std::cout << add_nums(2, "asdf", 234) << std::endl;
    return 0;
}

