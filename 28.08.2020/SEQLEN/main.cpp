#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

ll LengthOf(ll n){
    ll x = n;
    ll ans = 0;
    while (x>0) {
        x = x/10;
        ans = ans + 1;
    }
    return ans;
}

ll CalLen(ll n) {
    ll k = 1;
    ll ans = 0;
    ll l = LengthOf(n);
    for (int i = 1; i <= l-1; i++) {
        ans = ans + (9*k)*i;
        k = k*10;
    }
    ans = ans + ((n - k)+1)*l;
    return ans;
}

int main()
{
    ll n;
    fi.open("SEQLEN.INP");
    fo.open("SEQLEN.OUT");
    fi >> n;
    fo << CalLen(n);
    return 0;
}
