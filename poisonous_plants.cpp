#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef  pair<int,int> int_pair;

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
    os << "<" << p.first << "," << p.second << ">";
    return os;
}


template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
    os << "[";
    for (T t: v) {
        os << t << " ";
    }
    os << "]";
    return os;
}

int solve() {
    int n;
    cin >> n;

    int ans = 0;
    vector<int_pair> s;
    vector<int> v(n);
    vector<int> h(n, -1);
    for (int i = 0; i < n; i += 1) {
        int j;
        cin >> j;

        v[i] = j;

        int_pair p = make_pair(j, i);

        while (s.size() && s.back().first >= j) {
            s.pop_back();
        }

        if (s.size() > 0) {
            h[i] = s.back().second;
        }
        s.push_back(p);
    }

    //cout << h << endl;
    vector<int> h2(n);
    for (int i = 0; i < n; i += 1) {
        h2[i] = i - h[i];
    }

    cout << v << endl;
    cout << h << endl;
    cout << h2 << endl;

    //cout << ans << endl;

    return 0;
}

vector<int> pass(const vector<int>& v) {
    for (int i = 1; i < v.size(); i += 1) {
        if (v[i] > v[i-1]) {
        }
    }
}

int main() {
    return 0;
}
