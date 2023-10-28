#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

ll Groups(ll m, ll n, ll k) {
    ll t = min(m/2, n);
    ll l = (m+n) - 3*t;
    while (l < k) {
        l = l + 3;
        t--;
    }
    return t;
}

int main()
{
    ll m,n,k;
    fi.open("LARES.INP");
    fo.open("LARES.OUT");
    fi >> m >> n >> k;
    fo << Groups(m,n,k);
    return 0;
}
