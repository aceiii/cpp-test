

#include <iostream>
#include <sstream>

using namespace std;


long big_mod(long a, long b, long c) {
    if (a == 0 || b == 0) {
        return 0;
    }

    if (a == 1) {
        return b;
    }
    
    if (b == 1) {
        return a;
    }

    // returns: (a * b/2) mod c
    long a2 = big_mod(a, b/2, c);

    // even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c 
        return (a2 + a2) % c;
    } else {
        // odd exponent
        //  [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % c) + (a2 + a2)) % c;
    }
}


struct big_mod_t {
    long res;
    string work;
};

ostream& operator << (ostream& os, const big_mod_t& a) {
    os << a.work << " = " << a.res;
    return os;
}

big_mod_t big_mod2(long a, long b, long c) {
    if (a == 0 || b == 0) {
        big_mod_t zero;
        zero.res = 0;
        zero.work = "0";
        return zero;
    }

    if (a == 1) {
        big_mod_t alpha;
        alpha.res = b;

        ostringstream os;
        os << b;
        alpha.work = os.str();
        return alpha;
    }
    
    if (b == 1) {
        big_mod_t beta;
        beta.res = a;

        ostringstream os;
        os << a;
        beta.work = os.str();
        return beta;
    }

    // returns: (a * b/2) mod c
    //long a2 = big_mod2(a, b/2, c);
    big_mod_t res = big_mod2(a, b/2, c);
    long a2 = res.res;

    // even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c 
        //return (a2 + a2) % c;
        res.res = (a2 + a2) % c; 

        ostringstream os;
        os << "(" << res.work << " + " << res.work << ") % " << c;
        res.work = os.str();
    } else {
        // odd exponent
        //  [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        res.res = ((a % c) + (a2 + a2)) % c;

        ostringstream os;
        os << "((" << a << " % " << c << ") + (" << res.work << " + " << res.work << ")) % " << c;
        res.work = os.str();
    }

    return res;
}


int main(int argc, char* argv[]) {
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(int64_t): " << sizeof(int64_t) << endl;

    cout << big_mod2(64545, 58971, 144) << endl;


    return 0;
}



