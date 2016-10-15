#include <vector>
#include <iostream>
#include <memory>
#include <exception>

using namespace std;


class widget {
};

class gadget {
};

class exceptional_widget : public widget {
public:
    exceptional_widget():widget() {
        throw "Widget Constructor Exception!";
    }
};

class exceptional_gadget : public gadget {
public:
    exceptional_gadget():gadget() {
        throw "Gadget Constructor Exception!";
    }
};


void sink(unique_ptr<widget> w, unique_ptr<gadget> g) {
    cout << "Sink(" << (w == nullptr ? "NULL" : "widget") << ", " << (g == nullptr ? "NULL" : "gadget") << ")" << endl;
}

void unsafe_sink() {
    sink(unique_ptr<widget>{new exceptional_widget{}},
         unique_ptr<gadget>{new exceptional_gadget{}});
}

void unsafe_sink2() {
    sink(make_unique<widget>(),
         unique_ptr<gadget>{new exceptional_gadget{}});
}

void safe_sink() {
    sink(make_unique<exceptional_widget>(),
         make_unique<exceptional_gadget>());
}

int main(int argc, char** argv) {
    //unsafe_sink();
    //unsafe_sink2();

    safe_sink();

    return 0;
}


