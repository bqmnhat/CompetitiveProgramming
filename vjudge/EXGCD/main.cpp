#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxK 5
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int t, k;
ll A[MaxK+5], B[MaxK+5], MinBi = 1e9 + 7, phi[MaxN+5];

void ReadData() {
    MinBi = 1e9 + 7;
    for (int i=1; i<=k; i++) {
        cin >> A[i] >> B[i];
        MinBi = min(MinBi, B[i]);
    }
}

void CalPhi() {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= MaxN; i++)
        phi[i] = i - 1;
    for (int i = 2; i <= MaxN; i++)
        for (int j = 2 * i; j <= MaxN; j += i)
              phi[j] -= phi[i];
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

ll ModInv(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

ll Solution() {
    ll Q = 1;
    for (int i=1; i<=k; i++)
        Q = (Q*(B[i] - A[i] + 1LL))%Mod;
    ll P = 0;
    for (ll d = 1; d<=MinBi; d++) {
        ll tmp = 1;
        for (int i=1; i<=k; i++)
            tmp = (tmp*((B[i]/d) - ((A[i] - 1LL)/d)))%Mod;
        P = (P + tmp*phi[d])%Mod;
    }
    ll ans = ((Mod - P)*ModInv(Q, Mod))%Mod;
    if (ans >= 0)
        return ans;
    return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> k;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalPhi();
    cin >> t;
    Solve();
    return 0;
}
