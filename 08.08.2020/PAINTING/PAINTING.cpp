#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi;
ofstream fo;

long long CountFac(long long n) {
    long long tmp = 1, d = 0, x = n;
    long long i = 2;
    long long m = (int)sqrt(x);
    while ((x > 1) and (i <= m)) {
        d = 0;
        while (x%i == 0) {
            d = d + 1;
            x = x/i;
        }
        if (d>0)
            tmp = tmp * (d + 1);
        i = i + 1;
    }
    if (x>1)
        tmp = tmp*2;
    return tmp;
}

int main()
{
    long long n;
    fi.open("PAINTING.INP");
    fo.open("PAINTING.OUT");
    fi >> n;
    long long m = CountFac(n);
    fo << n - m << " " << m;
    return 0;
}
