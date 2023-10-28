#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

void PrimeFactors(ll n) {
    ll i = 2,m = (int)sqrt(n);
    ll d;
    while ((n>1) and (i<=m)) {
        d = 0;
        while (n%i==0) {
            d = d + 1;
            n = n/i;
        }
        if (d > 0) {
            fo << i << " ";
        }
        i++;
    }
    if (n>1) {
        fo << n;
    }
}

int main()
{
    ll n;
    fi.open("PRIMEDIV.INP");
    fo.open("PRIMEDIV.OUT");
    fi >> n;
    PrimeFactors(n);
    return 0;
}
