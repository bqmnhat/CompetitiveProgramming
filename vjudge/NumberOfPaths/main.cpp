#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
#define MaxFac 4000
#define MaxQ 110
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, q;
ll dp[MaxQ+1], Fac[MaxFac+1], InvFac[MaxFac+1];
pii a[MaxQ+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=q; i++)
        cin >> a[i].first >> a[i].second;
    a[0] = pii(0, 0);
    a[q+1] = pii(n-1, n-1);
}

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e > 0) {
        if (e&1)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InvertMod(ll val, ll Mod) {
    return (FastPow(val, Mod-2, Mod));
}

void MakeFac() {
    ll ans = 1;
    Fac[0] = Fac[1] = 1;
    for (ll i=2; i<=MaxFac; i++) {
        Fac[i] = (Fac[i-1]*1LL*i)%Mod;
        InvFac[i] = InvertMod(Fac[i], Mod);
    }
}

ll CalFromAToB(pii A, pii B) {
    ll Deno = Fac[B.first - A.first + B.second - A.second];
    ll Nume = (InvFac[B.first - A.first]*InvFac[B.second - A.second])%Mod;
    ll ans = (Deno*Nume)%Mod;
    return ans;
}

ll Solution() {
    sort(a, a+q+1);
    dp[0] = 1;
    for (int i=1; i<=q+1; i++)
        dp[i] = (dp[i-1]*CalFromAToB(a[i-1], a[i]))%Mod;
    return dp[q+1];
}

void Solve() {
    MakeFac();
    for (int i=1; i<=t; i++) {
        cin >> n >> q;
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
