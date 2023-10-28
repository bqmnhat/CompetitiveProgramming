#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ID, k;

ll Larger(ll x) {
    ll cnt = 0;
    for (ll u = 1; u*u <= x; u++)
        cnt += ll(sqrt(x - (u*u)));
    return cnt;
}

ll BinSearchKTH(ll k) {
    ll lo = 2, hi = 1e12, ans = 0;
    while (lo <= hi) {
        ll x = lo + ((hi - lo)/2);
        if (Larger(x) >= k) {
            ans = x;
            hi = x-1LL;
        }
        else
            lo = x+1LL;
    }
    return ans;
}

int main()
{
    cin >> ID >> k;
    cout << BinSearchKTH(k);
    return 0;
}
