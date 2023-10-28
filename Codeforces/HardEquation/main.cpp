#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a, b, m;

ll Solution() {
    if (a == 0) {
        if (b != 0)
            return 0;
        return 1;
    }
    ll g, k = 1, add = 0;
    while ((g = __gcd(a, m)) > 1) {
        if (b == k)
            return add;
        b /= g;
        m /= g;
        add++;
        k = (k * (a/g))%m;
    }
    unordered_map<ll, ll> ma;
    ll n = sqrt(m) + 1, an = 1;
    for (int i=0; i<n; i++)
        an = (an * a)%m;
    for (ll q = 0, cur = b; q <= n; q++) {
        ma[cur] = q;
        cur = (cur * a)%m;
    }
    for (ll p = 1, cur = k; p <= n; p++) {
        cur = (cur * an)%m;
        if (ma.count(cur)) {
            ll ans = n*p - ma[cur] + add;
            if (ans <= 1e17)
                return ans;
        }
    }
    ma.clear();
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b >> m;
        cout << Solution() << '\n';
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
