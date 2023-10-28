#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi;
ofstream fo;

long long SqareCount(long long m, long long n) {
    long long tmp = 0, a = (int)sqrt(m*n);
    while ((n>=1) and (m>=1)) {
        tmp = tmp + m*n;
        m = m - 1;
        n = n - 1;
    }
    return tmp;
}

int main()
{
    long long m,n;
    fi.open("CNTSQR.INP");
    fo.open("CNTSQR.OUT");
    fi >> m >> n;
    fo << SqareCount(m,n);
    return 0;
}
