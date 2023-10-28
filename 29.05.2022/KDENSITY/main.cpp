#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, k;

bool IsSquare(ll x) {
    ll tmp = sqrt(x);
    return (tmp*tmp == x);
}

ll CountPairs() {
    ll ub = cbrt(b);
    ll ans = 0;
    for (ll i=1; i<=ub; i++) {
        if (i*i*i < a)
            continue;
        ll tmp1 = sqrt(min(b, k + i*i*i)), tmp2 = sqrt(max(i*i*i, a));
        ans += tmp1 - tmp2;
        if (IsSquare(max(i*i*i, a)))
            ans++;
        tmp1 = sqrt(min(b, i*i*i)), tmp2 = sqrt(max(i*i*i-k, a));
        ans += tmp1 - tmp2;
        if (IsSquare(max(i*i*i-k, a)))
            ans++;
        if (IsSquare(i*i*i))
            ans--;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("KDENSITY.INP", "r", stdin);
    freopen("KDENSITY.OUT", "w", stdout);
    cin >> a >> b >> k;
    cout << CountPairs();
    return 0;
}
