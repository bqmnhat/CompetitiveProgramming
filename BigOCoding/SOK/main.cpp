#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ID, k;

ll LargerThan(ll x) {
    x--;
    ll ans = (x/3) + (x/5) + (x/7) - (x/15) - (x/21) - (x/35) + (x/105);
    return ans;
}

ll BinSearchK(ll k) {
    ll lo = 3, hi = 1e18, ans = 0;
    while (lo <= hi) {
        ll x = lo + (hi - lo)/2;
        if (LargerThan(x) >= k - 1LL) {
            if (LargerThan(x) == k - 1LL)
                ans = x;
            hi = x - 1LL;
        }
        else
            lo = x + 1LL;
    }
    return ans;
}

ll Solution(ll k) {
    ll ans = BinSearchK(k);
    while ((ans % 3 != 0) && (ans % 5 != 0) && (ans % 7 != 0))
        ans++;
    return ans;
}

int main()
{
    cin >> ID >> k;
    cout << Solution(k);
    return 0;
}
