#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

long long ATM(long long a, long long b, long long c, long long n) {
    long long d = 0,x = 0,y,z = 0;
    while ((z <= c) and (z <= n/20)) {
        y = 0;
        while ((y <= b) and (y <= n/10)) {
            x = (n - 20*z - 10*y)/5;
            if ((5*x + 10*y + 20*z == n) and (x <= a) and (x >= 0))
                d = d + 1;
            y = y + 1;
        }
        z = z + 1;
    }
    return d;
}

int main()
{
    long long a,b,c,n;
    fi.open("ATM.INP");
    fo.open("ATM.OUT");
    fi >> a >> b >> c >> n;
    fo << ATM(a,b,c,n);
    return 0;
}
