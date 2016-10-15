#include <gc_cpp.h>
#include <gc/gc_allocator.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <chrono>
#include <thread>


struct Bar {
    std::string s;
    int a;
    float b;
    double c;
};

class Foo {
    std::string name;

    double someValue;
    double someOtherValue;
    int wtf;
    float a;
    char c1;
    char c2;
    double asdf;

    Bar bar;

public:
    Foo(const std::string& name):name(name) {}
    ~Foo() {
        std::cout << "Deallocating Foo(" << name << ")" << std::endl;
    }

public:
    std::string getName() const {
        return name;
    }
};

class Foo2: public gc_cleanup, public Foo {
public:
    Foo2(const std::string& name):Foo(name) {}
};

/*
int main(int argc, char** argv) {
    GC_INIT();
    for (int i = 0; i < 1000000; i += 1) {
        int** p = (int**)GC_MALLOC(sizeof(int*));
        int* q = (int*)GC_MALLOC_ATOMIC(sizeof(int));
        assert(*p == 0);
        *p = (int*)GC_REALLOC(q, 2 * sizeof(int));
        if (i % 10000 == 0) {
            std::cout << "Heap size = " << GC_get_heap_size() << std::endl;
        }
    }

    return 0;
}
*/


static int i = 0;
Foo* leaking_func() {
    std::stringstream s;
    s << "GC.Foo[" << ++i << "]";

    //auto f = new (UseGC) Foo(s.str()); // doesn't call destructor
    // auto f = new Foo(s.str()); // no gc
    auto f = new Foo2(s.str());
    std::cout << "Created: " << f->getName() << std::endl;

    return f;
}

int main(int argc, char** argv) {
    auto foo = new Foo("Hello");
    auto foo2 = new (UseGC) Foo("Blah!");

    std::cout << GC_get_heap_size() << std::endl;
    std::cout << foo->getName() << std::endl;
    std::cout << foo2->getName() << std::endl;

    std::vector<Foo*, gc_allocator<Foo*> > ptrs;
    auto start = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::seconds(0);
    int i = 0;
    do {
        auto fp = leaking_func();
        if (i % 10 == 1) {
            std::cout << "Saving foo " << fp->getName() << std::endl;
            ptrs.push_back(fp);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        //GC_gcollect();

        i += 1;

        auto now = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start);
        std::cout << "elapsed: " << elapsed.count() << "secs" << std::endl;
    } while(elapsed.count() < 60);

    GC_gcollect();
    return 0;
}


