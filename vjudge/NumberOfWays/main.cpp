#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000010
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int t;
ll n, k, Fact[MaxN+5], InvFact[MaxN+5];

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
    return (FastPow(val, Mod-2, Mod));
}

void FindFact() {
    Fact[0] = 1;
    InvFact[0] = InvMod(0, Mod);
    for (ll i=1; i<=MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InvMod(Fact[i], Mod);
    }
}

ll nCk(ll n, ll k) {
    if (n < k)
        return 0;
    ll ans = ((Fact[n]*InvFact[n-k])%Mod * InvFact[k])%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ll ans = ((2*nCk(n+k+1LL, k+2))%Mod - n + Mod)%Mod;
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    FindFact();
    cin >> t;
    Solve();
    return 0;
}
