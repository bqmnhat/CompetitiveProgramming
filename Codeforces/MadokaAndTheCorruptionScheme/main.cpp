#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, k;
ll Fac[MaxN+5], InvFac[MaxN+5];

ll FastPow(ll base, ll e, ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll ModularInverse(ll x, ll Mod) {
    return FastPow(x, Mod-2, Mod);
}

void MakeFac() {
    Fac[0] = 1;
    InvFac[0] = ModularInverse(1, Mod);
    for (int i=1; i<=n; i++) {
        Fac[i] = (Fac[i-1]*i)%Mod;
        InvFac[i] = ModularInverse(Fac[i], Mod);
    }
}

ll CHOOSE(int k, int n) {
    if (k > n)
        return 0;
    ll Nume = Fac[n];
    ll Deno = (InvFac[n-k]*InvFac[k])%Mod;
    return ((Nume*Deno)%Mod);
}

ll Solution() {
    ll ans = 0;
    for (int i=0; i<=min(k, n); i++)
        ans = (ans + CHOOSE(i, n))%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    MakeFac();
    cout << Solution();
    return 0;
}
