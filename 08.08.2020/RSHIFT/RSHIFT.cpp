/**
Cong thuc shift phai 1 so: n = (n%10)p + n/10
voi p = 10^(length(n) - 1);
**/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

void Length(long long n, long long &l, long long &p) {
    p = 1;
    l = 0;
    long long x = n;
    while (x > 0) {
        x = x/10;
        l = l + 1;
        p = p * 10;
    }
    p = p/10;
}

long long MaxShift(long long n) {
    long long p,l;
    Length(n,l,p);
    long long ans = n;
    for (int i = 1; i<l ; ++i) {
        if (n%10 == 0)
            p = p/10;
        n = (n%10)*p + n/10;
        if (n > ans)
            ans = n;
    }
    return ans;
}

int main()
{
    long long n;
    fi.open("RSHIFT.INP");
    fo.open("RSHIFT.OUT");
    fi >> n;
    fo << MaxShift(n);
    return 0;
}
