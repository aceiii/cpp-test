
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


template <typename T>
class MyGenericClass {

    T val;

public:
    MyGenericClass() {}
    MyGenericClass(const T& v):val(v) {}

    ~MyGenericClass() {}

public:

    string toString() const {
        stringstream ss;
        ss << val;
        return ss.str();
    } 
};


// specialize MyGenericClass for int
template <>
class MyGenericClass<int> {
    
    int val;

public:
    MyGenericClass():val(-1) {}
    MyGenericClass(int v):val(v) {}

    ~MyGenericClass() {}

public:

    string toString() const {
        stringstream ss;
        ss << "MyGenericClass<int> " << val;
        return ss.str();
    }
};

template <typename T>
ostream& operator<< (ostream& os, const MyGenericClass<T>& rhs) {
    os << rhs.toString();
    return os;
}

int main() {
    MyGenericClass<bool> b(false);
    MyGenericClass<char> c('f');
    MyGenericClass<int> i(99);
    MyGenericClass<float> f(3.14f);
    MyGenericClass<string> s("test");

    cout << b << endl;
    cout << c << endl;
    cout << i << endl; // should display custom message
    cout << f << endl;
    cout << s << endl;

    return 0;
}

