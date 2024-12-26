#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
ll n, m, k;

ll cntMultiplePairs(ll val) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += min((val/i), m);
    return ans;
}

ll Solution() {
    ll lo = 1, hi = n*m, ans = -1;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        ll cnt = cntMultiplePairs(mid);
        if (cnt >= k) {
            ans = mid;
            hi = mid - 1LL;
        }
        else
            lo = mid + 1LL;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    cout << Solution();
    return 0;
}
