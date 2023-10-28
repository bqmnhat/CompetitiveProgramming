#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

int LofX(long long x) {
    int tmp = 0;
    long long a = x;
    while (a>0) {
        a = a/10;
        tmp = tmp + 1;
    }
    return tmp;
}

bool IsHNum(long long x) {
    long long a = x;
    int l = LofX(a);
    if (l%2 == 0) {
        int k = l/2, t1 = 0, t2 = 0;
        for (int i = 1; i <= l; i++) {
            t1 = t1 + a%10;
            a = a/10;
            if (i == k) {
                t2 = t1;
                t1 = 0;
            }
        }
        if (t1 == t2)
            return true;
    }
    return false;
}

int main()
{
    long long n;
    bool found = false;
    fi.open("HNUM.INP");
    fo.open("HNUM.OUT");
    fi >> n;
    for (int i = 1; i<=n; i++) {
        if (IsHNum(i)){
            fo << i << endl;
            found = true;
        }
    }
    if (found == false) {
        fo << -1;
    }
    return 0;
}
