#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll l, r, s;

ll SumOfDig(ll k) {
    ll ans = 0;
    while (k > 0) {
        ans += k%10;
        k = k/10;
    }
    return ans;
}

ll BinSearch(ll lo, ll hi, ll r) {
    ll ans = 0;
    while (lo <= hi) {
        ll m = (lo + hi)/2;
        if (m - SumOfDig(m) >= s) {
            ans = r - m + 1LL;
            hi = m - 1LL;
        }
        else
            lo = m + 1LL;
    }
    return ans;
}

void Solve() {
    for (int i = 1; i<=t; i++) {
        cin >> l >> r >> s;
        ll ans = BinSearch(1, r, r) - BinSearch(1, l-1LL, l-1LL);
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
