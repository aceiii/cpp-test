#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


template <typename T, typename C = std::less<T>>
struct print_heap {
    std::vector<T> list;

    print_heap(const std::vector<T>& v, const C& c = C()) {
        std::vector<T> tmp_list = v;
        while (!tmp_list.empty()) {
            std::pop_heap(tmp_list.begin(), tmp_list.end(), C());
            list.push_back(tmp_list.back());
            tmp_list.erase(tmp_list.end() - 1);
        }
    }

};

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    if (!v.empty()) {
        os << *v.begin();
        std::for_each(v.begin() + 1, v.end(), [&] (const T& t) {
            os << ", " << t;
        });
    }
    os << " ]";
    return os;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const print_heap<T>& pt) {
    return (os << "heap " << pt.list << std::endl);
}


template <typename T, typename C = std::less<T> >
void heap_insert(std::vector<T>& v, T t, C c = std::less<T>()) {
    v.push_back(t);
    push_heap(v.begin(), v.end(), c);
}


template <typename T, typename C = std::less<T> >
class Pq {
public:
    //Pq(C c = std::less<T>()):_cmp(c) {}
    Pq(const C& c = C()):_cmp(c) {}

    void insert(const T& t) {
        _list.push_back(t);
        std::push_heap(_list.begin(), _list.end(), _cmp);
    }

    std::string to_str() const {
        std::stringstream ss;
        ss << print_heap<T, C>(_list);

        return ss.str();
    }
private:
    C _cmp;
    std::vector<T> _list;
};

auto main() -> int {

    /*
    std::vector<int> a;
    heap_insert(a, 3);
    heap_insert(a, 10);
    heap_insert(a, 2);
    heap_insert(a, 1);
    heap_insert(a, 7);
    */
    //std::cout << a << std::endl;
    //std::cout << print_heap<int>(a) << std::endl;


    Pq<int> pq;
    pq.insert(3);
    pq.insert(10);
    pq.insert(5);
    pq.insert(1);
    pq.insert(2);
    pq.insert(7);

    std::cout << pq.to_str() << std::endl;

    return 0;
}




