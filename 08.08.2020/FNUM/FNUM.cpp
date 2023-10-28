#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi;
ofstream fo;

long long SumFac(long long x) {
    long long tmp = 0;
    int m = (int)sqrt(x);
    for (int i = 2; i <= m; i++) {
        if (x%i == 0)
            tmp = tmp + i + (x/i);
    }
    if (m*m == x)
        tmp = tmp - m;
    return tmp;
}

void FindFPairs(long long n) {
    long long y;
    bool TimDc = false;
    for (long long x = 1; x <= n; x++) {
        y = SumFac(x);
        if ((x == SumFac(y)) and (x < y) and (y<=n)) {
            fo << x << " " << y << endl;
            TimDc = true;
        }
    }
    if (TimDc == false)
        fo << -1;
}

int main()
{
    long long n;
    fi.open("FNUM.INP");
    fo.open("FNUM.OUT");
    fi >> n;
    FindFPairs(n);
    return 0;
}
