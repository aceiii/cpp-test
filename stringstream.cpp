#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char** argv) {
    std::stringstream ss;

    ss << 1 << 3 << 5 << 9;

    //std::cout << ss.str() << std::endl;

    int num = 0;
    //ss >> num;

    std::cout << "fail: " << std::boolalpha << ss.fail() << std::endl;
    //std::cout << "num: " << num << std::endl;

    ss << "9" << "9234";
    ss.seekg(0, ss.beg);
    ss.seekp(0, ss.beg);
    ss.clear();
    std::cout << "fail2: " << std::boolalpha << ss.fail() << std::endl;
    std::cout << "ss2: " << ss.str() << std::endl;

    ss >> num;

    std::cout << "fail3: " << std::boolalpha << ss.fail() << std::endl;
    std::cout << "num2: " << num << std::endl;
    std::cout << "ss3: " << ss.str() << std::endl;

    return 0;
}

