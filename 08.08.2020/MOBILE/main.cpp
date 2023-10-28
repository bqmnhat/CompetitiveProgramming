#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

long long CallCost(long long p, long long t, long long n) {
    long long mi,m,bl;
    mi = (long long)n/60;
    m = n - mi*60;
    if (m%6 == 0)
        bl = (long long)m/6;
    else
        bl = (long long)m/6 + 1;
    return p*mi + t*bl;
}

int main()
{
    long long p,t,n;
    fi.open("MOBILE.INP");
    fo.open("MOBILE.OUT");
    fi >> p >> t >> n;
    fo << CallCost(p,t,n);
    return 0;
}
