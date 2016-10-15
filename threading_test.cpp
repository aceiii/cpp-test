#include <iostream>
#include <thread>

void mythread() {
    std::cout << "my thread!" << std::endl;
}

int test1() {
    std::thread foo;
    std::thread bar(mythread);

    std::cout << "Joinable after construction:\n" << std::boolalpha;
    std::cout << "foo: " << foo.joinable() << '\n';
    std::cout << "bar: " << bar.joinable() << '\n';

    if (foo.joinable()) {
        foo.join();
    }

    if (bar.joinable()) {
        bar.join();
    }

    std::cout << "Joinable after joining:\n" << std::boolalpha;
    std::cout << "foo: " << foo.joinable() << '\n';
    std::cout << "bar: " << bar.joinable() << '\n';

    return 0;
}


void print_str(const std::string& s, int n) {
    std::thread::id thread_id = std::this_thread::get_id();
    for (int i = 0; i < n; i += 1) {
        std::cout << thread_id << ":" << s << ":" << n << std::endl;
    }
}

std::chrono::milliseconds interval(20);
std::mutex mutex;

void print_str_safe(const std::string& s, int n) {
    std::thread::id thread_id = std::this_thread::get_id();
    for (int i = 0; i < n; i += 1) {
        while (true) {
            if (mutex.try_lock()) {
                std::cout << thread_id << ":" << s << ":" << n << std::endl;
                mutex.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
                break;
            } else {
                std::this_thread::sleep_for(interval);
            }
        }
    }
}

void print_str_safe2(const std::string& s, int n) {
    std::thread::id thread_id = std::this_thread::get_id();
    for (int i = 0; i < n; i += 1) {
        {
            std::lock_guard<std::mutex> lock(mutex);
            std::cout << thread_id << ":" << s << ":" << n << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}
void test2() {
    std::cout << "This thread: " << std::this_thread::get_id() << std::endl;

    std::string s1 = "Hello World!";
    std::string s2 = "Foobar";

    std::thread t1(print_str, std::cref(s1), 10000);
    std::thread t2(print_str, std::cref(s2), 11100);

    t1.join();
    t2.join();
}

void test3() {
    std::cout << "This thread: " << std::this_thread::get_id() << std::endl;

    std::string s1 = "Hello World!";
    std::string s2 = "Foobar";

    std::thread t1(print_str_safe, std::cref(s1), 10000);
    std::thread t2(print_str_safe, std::cref(s2), 11100);

    t1.join();
    t2.join();
}

void test4() {
    std::cout << "This thread: " << std::this_thread::get_id() << std::endl;

    std::string s1 = "Hello World!";
    std::string s2 = "Foobar";

    std::thread t1(print_str_safe2, std::cref(s1), 10000);
    std::thread t2(print_str_safe2, std::cref(s2), 11100);

    t1.join();
    t2.join();
}

int main() {
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}

