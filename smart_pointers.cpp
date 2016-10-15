#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <memory>

using namespace std;


class MyClass {

    int val;

public:
    MyClass(int v):val(v) {
        cout << "MyClass constructor(" << val << ")" << endl;
    }

    ~MyClass() {
        cout << "MyClass destructor(" << val << ")" << endl;
    }
};

void stackTest() {
    cout << " == STACK TEST ===========" << endl;

    MyClass c1(1);
    MyClass c2(2);
    MyClass c3(3);

    cout << " == END STACK TEST =======" << endl;
}

void heapTest() {
    cout << " == HEAP TEST ============" << endl;

    MyClass c1(99);

    MyClass* c2 = new MyClass(123);
    MyClass* c3 = new MyClass(555);

    delete c3;
    // delete c2;

    cout << " == END HEAP TEST ========" << endl;
}

void smartPointerTest() {
    cout << " == SMART POINTER TEST ===" << endl;

    unique_ptr<MyClass> p1 = make_unique(3);

    cout << " == END SMART POINTER TEST" << endl;
}


int main() {

    stackTest();
    heapTest();
    smartPointerTest();

    return 0;
}

