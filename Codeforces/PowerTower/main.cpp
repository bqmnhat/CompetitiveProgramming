#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, m, l, r, q;
ll a[MaxN+1];
map<ll, ll> phi;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll FindPhi(ll val) {
    ll ans = val;
    int tmp = sqrt(val), i = 2;
    while ((i <= tmp) && (val > 1)) {
        if (val%i == 0)
            ans = (ans/i)*(i-1LL);
        while (!(val%i))
            val /= i;
        i++;
    }
    if (val > 1)
        ans = (ans/val)*(val - 1LL);
    return ans;
}

void MakePhi() {
    ll tmp = m;
    while (tmp != 1) {
        phi[tmp] = FindPhi(tmp);
        tmp = phi[tmp];
    }
}

ll mod(ll val, ll Mod) {
    if (val < Mod)
        return val;
    return (val%Mod + Mod);
}

ll FastPow(ll base, ll e, ll Mod) {
    ll ans = 1LL;
    while (e) {
        if (e&1)
            ans = mod(ans*base, Mod);
        base = mod(base*base, Mod);
        e >>= 1LL;
    }
    return ans;
}

ll Solution(ll x, ll Mod) {
    if ((Mod == 1) || (x == r))
        return mod(a[x], Mod);
    return (FastPow(a[x], Solution(x+1, phi[Mod]), Mod));
}

void Solve() {
    MakePhi();
    for (int i=1; i<=q; i++) {
        cin >> l >> r;
        cout << Solution(l, m)%m << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cin >> q;
    Solve();
    return 0;
}
