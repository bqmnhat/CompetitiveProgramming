#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e9+7;
int t, n, k;
ll Fact[MaxN+5], InvFact[MaxN+5], a[MaxN+5];

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

ll ModInverse(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

void MakeInvFact() {
    Fact[0] = 1;
    InvFact[0] = ModInverse(Fact[0], Mod);
    for (ll i=1; i<=MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = ModInverse(Fact[i], Mod);
    }
}

ll nCk(ll n, ll k) {
    if (k == n)
        return 1;
    if (n < k)
        return 0;
    return (((Fact[n]*InvFact[k])%Mod)*InvFact[n-k])%Mod;
}

ll Solution() {
    ll ans = 0;
    sort(a+1, a+1+n, greater<ll>());
    for (ll i=1; i<=n; i++)
        ans = (ans + (a[i]*nCk(i-1, k-1))%Mod)%Mod;
    return ans;
}

void Solve() {
    MakeInvFact();
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
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
