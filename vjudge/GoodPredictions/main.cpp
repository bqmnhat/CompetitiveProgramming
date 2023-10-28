#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
ll Fact[MaxN+5], InvFact[MaxN+5], N, W, T, R;

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1LL)
            ans = (ans * base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InvMod(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

void FindFact() {
    Fact[0] = 1;
    InvFact[0] = InvMod(1, Mod);
    for (int i=1; i<=MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InvMod(Fact[i], Mod);
    }
}

ll nCk(ll n, ll k, const ll Mod) {
    if (n < k)
        return 0;
    ll deno = Fact[n];
    ll nume = (InvFact[k]*InvFact[n-k])%Mod;
    ll ans = (deno*nume)%Mod;
    return ans;
}

ll Solution() {
    ll ans = (nCk(N, W, Mod)*nCk(N-W, T, Mod))%Mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    FindFact();
    cin >> N >> W >> T >> R;
    cout << Solution();
    return 0;
}
