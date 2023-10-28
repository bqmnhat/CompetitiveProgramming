#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef long long ll;
int t;
ll m, n, r, Fact[MaxN+5][MaxN+5], InvFact[MaxN+5][MaxN+5], Primes[16] = {-1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

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

void MakeFactWithR(const ll r) {
    Fact[r][0] = 1;
    InvFact[r][0] = InvMod(1LL, r);
    for (int i=1; i<=MaxN; i++) {
        Fact[r][i] = (Fact[r][i-1]*i)%r;
        InvFact[r][i] = InvMod(Fact[r][i], r);
    }
}

void FindAllFact() {
    for (int i=1; i<=15; i++)
        MakeFactWithR(Primes[i]);
}

vector<ll> FactorizeR(ll r) {
    vector<ll> ans;
    ans.clear();
    for (int i=2; i<=50; i++) {
        if (r%i == 0) {
            ans.push_back(i);
            r /= i;
        }
    }
    return ans;
}

vector<ll> GetPresentation(ll val, ll base) {
    vector<ll> ans;
    ans.clear();
    while (val > 0) {
        ll tmp = val%base;
        ans.push_back(tmp);
        val /= base;
    }
    return ans;
}

ll nCkSmall(ll n, ll k, const ll Mod) {
    if (n < k)
        return 0;
    ll ans = ((Fact[Mod][n]*InvFact[Mod][k])%Mod * InvFact[Mod][n-k])%Mod;
    return ans;
}

ll Lucas(ll n, ll k, const ll Mod) {
    if (n < k)
        return 0;
    vector<ll> Pn = GetPresentation(n, Mod);
    vector<ll> Pk = GetPresentation(k, Mod);
    ll ans = 1;
    for (int i=0; i<Pk.size(); i++)
        ans = (ans*nCkSmall(Pn[i], Pk[i], Mod))%Mod;
    return ans;
}

ll nCkBig(ll n, ll k, ll Mod) { // Chinese remainder theorem
    if (n < k)
        return 0;
    ll ans = 0;
    vector<ll> FactR;
    FactR = FactorizeR(Mod);
    for (int i=0; i<FactR.size(); i++) {
        ll mi = FactR[i];
        ll M_i = Mod/mi;
        ll Y_i = InvMod(M_i, mi);
        ll nCkModMi = Lucas(n, k, mi);
        ans = (ans + ((nCkModMi*M_i)%Mod * Y_i)%Mod)%Mod;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> r;
        cout << nCkBig(n, m, r) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    FindAllFact();
    cin >> t;
    Solve();
    return 0;
}
