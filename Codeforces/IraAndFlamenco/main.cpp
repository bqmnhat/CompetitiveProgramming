#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int t, n, m;
ll a[MaxN+5], PreProd[MaxN+5], freq[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InvMod(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

void MakeFreq() {
    sort(a+1, a+1+n);
    int cnt = 0, la = 0;
    for (int i=1; i<=n; i++) {
        cnt++;
        if (a[i] != a[i+1]) {
            la++;
            a[la] = a[i];
            freq[la] = cnt;
            cnt = 0;
        }
    }
    n = la;
}

void MakePreProd() {
    PreProd[0] = 1;
    for (int i=1; i<=n; i++)
        PreProd[i] = (PreProd[i-1]*freq[i])%Mod;
}

ll Solution() {
    MakeFreq();
    MakePreProd();
    int i = 1;
    ll ans = 0;
    for (int i=1; i<=n; i++)
        if ((i+m-1 <= n) && (a[i+m-1] - a[i] == m-1))
            ans = (ans + (PreProd[i+m-1] * InvMod(PreProd[i-1], Mod)))%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        memset(a, 0, sizeof(a));
        cin >> n >> m;
        ReadData();
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
