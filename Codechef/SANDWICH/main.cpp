#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, k, m, f[MaxN+5], d[MaxN+5], phi[MaxN+5];

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                d[i*j] = i;
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
    ll ans = 1%Mod;
    while (e) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

ll InvMod(ll val, const ll Mod) {
    return FastPow(val, phi[Mod]-1LL, Mod);
}

vector<pii> Factorize(int n) { //n <= 1e6
    unordered_map<int, int> mu;
    vector<pii> ans;
    ans.clear();
    while (n > 1) {
        int p = d[n];
        if (p == 0)
            p = n;
        n /= p;
        mu[p]++;
    }
    for (auto it = mu.begin(); it != mu.end(); it++)
        ans.push_back(pii((*it).first, (*it).second));
    return ans;
}

void Calf(ll p, ll n, ll m) {
    f[0] = f[1] = 1LL%m;
    for (ll i=2; i<=m; i++) {
        f[i] = f[i-1];
        if (i%p)
            f[i] = (f[i]*i) % m;
    }
}

void CalFAndE(ll n, ll p, ll m, ll& F, ll& E) {
    int r = 0;
    ll CurP = 1;
    E = 0;
    F = 1;
    while (CurP <= n) {
        ll tmp = n/CurP;
        ll TrueValOff = (FastPow(f[m], tmp/m, m)*f[tmp%m])%m;
        E += tmp;
        F = (F*TrueValOff)%m;
        if (CurP > n/p)
            break;
        CurP *= p;
        r++;
    }
}

ll nCkModmi(ll n, ll k, ll p, ll e) {
    ll pe = FastPow(p, e, 1e18+7);
    Calf(p, n, pe);
    ll Fn, Fk, Fnk, En, Ek, Enk;
    CalFAndE(n, p, pe, Fn, En);
    CalFAndE(k, p, pe, Fk, Ek);
    CalFAndE(n-k, p, pe, Fnk, Enk);
    ll PModPe = FastPow(p, En - Ek - Enk, pe)%pe;
    ll ans = (((Fn*InvMod(Fk, pe))%pe*InvMod(Fnk, pe))%pe * PModPe)%pe;
    return ans;
}

ll nCkBig(ll n, ll k, ll Mod) { // Chinese remainder theorem
    if (n < k)
        return 0;
    ll ans = 0;
    vector<pii> FactR;
    FactR = Factorize(Mod);
    for (int i=0; i<FactR.size(); i++) {
        ll mi = FactR[i].first;
        ll miWithPow = FastPow(mi, FactR[i].second, 1e18+7);
        ll M_i = Mod/miWithPow;
        ll Y_i = InvMod(M_i, miWithPow);
        ll nCkModMi = nCkModmi(n, k, mi, FactR[i].second);
        ans = (ans + ((nCkModMi*M_i)%Mod * Y_i)%Mod)%Mod;
    }
    return ans;
}

void SolveTestCase() {
    ll ans;
    ll CeilNDivK = ((n-1LL)/k + 1LL);
    if (n%k == 0)
        ans = 1;
    else
        ans = nCkBig(k-n%k+CeilNDivK-1LL, CeilNDivK-1LL, m);
    cout << CeilNDivK << ' ' << ans << '\n';
}

void Solve() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> m;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalPhi();
    MakeSieve();
    Solve();
    return 0;
}
