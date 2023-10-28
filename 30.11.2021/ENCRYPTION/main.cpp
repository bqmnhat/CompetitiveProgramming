#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;

ll FindNum(ll &w) {
    int d = 1;
    ll tmp = 10, m = 1, ans = 0;
    while (w > 0) {
        ll Num = tmp - m;
        if (w < Num*d*1LL)
            break;
        w -= (Num*d*1LL);
        ans += Num;
        m = tmp;
        d++;
        tmp *= 10;
    }
    if (w > 0) {
        ans += w/d;
        w = w%d;
    }
    return ans;
}

ll Solution() {
    if ((l == r) && (l <= 9))
        return 1;
    ll Numl, Numr;
    if (l <= 9) {
        Numl = l-1;
        l = 0;
    }
    else
        Numl = FindNum(l);
    if (r <= 9)
        Numr = r-1;
    else
        Numr = FindNum(r);
    if (l > 1)
        Numl++;
    ll ans = max(0LL, Numr - Numl);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ENCRYPTION.INP", "r", stdin);
    freopen("ENCRYPTION.OUT", "w", stdout);
    cin >> l >> r;
    cout << Solution();
    return 0;
}
