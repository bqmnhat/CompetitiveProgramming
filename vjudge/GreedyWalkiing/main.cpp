#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, a[MaxN+5];
ll Fact[MaxN+5], InvFact[MaxN+5];

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

void MakeFact() {
    Fact[0] = 1;
    InvFact[0] = InvMod(1, Mod);
    for (ll i=1; i<=MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InvMod(Fact[i], Mod);
    }
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        a[i] = abs(a[i] - tmp);
    }
}

ll Solution() {
    ll Deno = 0, Nume = InvMod(1, Mod);
    for (int i=1; i<=n; i++) {
        Deno += a[i];
        Nume = (Nume*InvFact[a[i]])%Mod;
    }
    Deno = Fact[Deno];
    ll ans = (Deno*Nume)%Mod;
    return ans;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeFact();
    Solve();
    return 0;
}
