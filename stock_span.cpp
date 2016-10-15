#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& os, const std::pair<T1, T2>& p) {
    os << "<" << p.first << "," << p.second << ">";
    return os;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (T n: v) {
        os << n << " ";
    }
    os << "]";
    return os;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > s;
    std::vector<int> h(n, -1);
    for (int i = 0; i < n; i += 1) {
        int j;
        std::cin >> j;

        std::pair<int, int> p = std::make_pair(j, i);

        //std::cout << "stack: " << s << std::endl;
        //std::cout << "h: " << h << std::endl;

        while (s.size() > 0 && s.back().first <= j) {
            std::pair<int, int> p2 = s.back();
            s.pop_back();
        }

        if (s.size() > 0) {
            h[i] = s.back().second;
        }
        s.push_back(p);

    }

    for (int i = 0; i < n; i += 1) {
        std::cout << (i - h[i]) << " ";
    }
    std::cout << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i += 1) {
        solve();
    }

    return 0;
}

