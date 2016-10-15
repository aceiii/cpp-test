
#ifndef __TEST_CLASS_H__
#define __TEST_CLASS_H__


#include <string>


class TestClass
{
public:
    TestClass();
    ~TestClass();

    void do_something(int a, const std::string &str = "") const;

protected:

private:
    const std::string _name;    
};


#endif//__TEST_CLASS_H__
