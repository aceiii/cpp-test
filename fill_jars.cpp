#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> jars;
    for (int i = 0; i < n; i += 1) {
        //jars[i] = 0;
    }

    //int avg = 0;
    int64_t t = 0;

    for (int i = 0; i < m; i += 1) {
        int a, b, k;
        cin >> a >> b >> k;
        
        //int q = double(b - a) + 1;
        //avg = (avg * n + q * k) / n;
        
        t = t + (b - a + 1) * k;
    }
    
    cout << t / int64_t(n) << endl;
    
    return 0;
}
