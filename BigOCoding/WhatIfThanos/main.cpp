#include <iostream>
#include <bits/stdc++.h>
#define MaxK 505
#define MaxN 200005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll Mod = 1e9 + 9;
int t;
ll Fac[MaxN+1], n, m, k, dp[MaxK+1], InvFac[MaxN+1];
pll a[MaxK+1];

void ReadData() {
    for (int i=1; i<=k; i++)
        cin >> a[i].first >> a[i].second;
    a[0] = pll(1, 1);
    a[k+1] = pll(n, m);
}

ll CalMod(ll val, ll Mod) {
    while (val >= Mod)
        val = val - Mod;
    return val;
}

ll FastPow(ll base, ll e, ll Mod) {
    ll ans = 1;
    base = base%Mod;
    while (e > 0) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InvertMod(ll val, ll Mod) {
    return FastPow(val, Mod - 2, Mod);
}

ll CalFac() {
    Fac[0] = 1;
    InvFac[0] = InvertMod(1, Mod);
    for (int i=1; i<=MaxN; i++) {
        Fac[i] = (Fac[i-1]*i)%Mod;
        InvFac[i] = InvertMod(Fac[i], Mod);
    }
}

ll CalFromAToB(pll A, pll B) { // A Further than B
    ll Num = Fac[A.first - B.first + A.second - B.second];
    ll ans = (((Num*InvFac[A.first - B.first])%Mod)*InvFac[A.second - B.second]%Mod)%Mod;
    return ans;
}

ll Solution() {
    sort(a+1, a+1+k);
    dp[0] = 1;
    for (int i=1; i<=k+1; i++) {
        dp[i] = CalFromAToB(a[i], a[0]);
        for (int j=1; j<i; j++)
            if (a[j].second <= a[i].second)
                dp[i] = CalMod(dp[i] - (dp[j]*CalFromAToB(a[i], a[j]))%Mod + Mod, Mod);
    }
    return dp[k+1];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> k;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalFac();
    cin >> t;
    Solve();
    return 0;
}
