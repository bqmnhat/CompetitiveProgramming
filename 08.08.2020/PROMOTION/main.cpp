#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

long long Exchange(long long n, long long k) {
    long long r = 0, d = 0;
    long long ans = 0, m = n;
    while (m >= k) {
        r = m%k;
        d = m/k;
        ans = ans + d;
        m = (d+r);
    }
    return ans;
}

int main()
{
    long long n,k;
    fi.open("PROMOTION.INP");
    fo.open("PROMOTION.OUT");
    fi >> n >> k;
    fo << Exchange(n,k);
    return 0;
}
