#include <iostream>
#include <vector>
#include <string>


class Foo {
    int _id;

public:
    Foo(int id):_id(id) {}
    virtual ~Foo() {}

    virtual void blah(const char* s) {
        std::cout << s << "::Foo: " << _id << std::endl;
    }
};

class Bar: public Foo {
    int _id;
public:
    Bar(int id):Foo(id),_id(id) {}

    virtual void blah(const char* s) {
        std::cout << s << "::Bar: " << _id << std::endl;
    }
};


class Foobar: public Bar {
    int _id;
public:
    Foobar(int id):Bar(id),_id(id) {}

    virtual void blah(const char* s) {
        std::cout << s << "::Foobar: " << _id <<std::endl;
    }
};


auto main() -> int {
    Foo f(1);
    Bar b(2);
    Foobar fb(3);

    f.blah("f");
    b.blah("b");
    fb.blah("fb");

    Foo& f2 = b;
    f2.blah("f2");

    // Compile time error:
    //Bar& b2 = f;
    //b2.blah("b2");

    Foo& f3 = fb;
    f3.blah("f3");

    Bar& b3 = fb;
    b3.blah("b3");

    // Compile error: reference cannot point to temporary object
    //Foo& f4 = Foobar(99);
    //f4.blah("f4");

    // Compile error
    //Foobar& fb2 = b3;
    //fb2.blah("fb2");

    Foobar& fb3 = dynamic_cast<Foobar&>(f3);
    fb3.blah("fb3");

    // Crash: unable to cast Foo into Foobar
    //Foobar& fb4 = dynamic_cast<Foobar&>(f);
    //fb4.blah("fb4");

    Foo& f5 = f3;
    f5.blah("f5");

    Foo* pf1 = &fb;
    pf1->blah("pf1");

    // Compile error: different pointer types
    //Foobar* pfb1 = pf1;
    //pfb1->blah("pfb1");

    Foobar* pfb2 = dynamic_cast<Foobar*>(&fb);
    pfb2->blah("pfb2");

    Foo* pf2 = dynamic_cast<Foo*>(&fb);
    pf2->blah("pf2");

    Foobar* pfb3 = dynamic_cast<Foobar*>(&f);
    if (pfb3 != nullptr) {
        // Segmentation fault if called naked
        pfb3->blah("pfb3");
    }

    return 0;
}

