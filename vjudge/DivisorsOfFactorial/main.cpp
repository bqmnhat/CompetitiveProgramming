#include<iostream>
#include<bits/stdc++.h>
#define MaxN 100005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll Mod = 1e9+7;
int t;
unordered_map<ll, ll> cnte;
ll d[MaxN+5], ans[MaxN+5], CurAns = 1;
pii Queries[MaxN+5];

void ReadData() {
    for (int i=1; i<=t; i++) {
        cin >> Queries[i].first;
        Queries[i].second = i;
    }
}

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                d[i*j] = i;
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

ll InvMod(ll val, const ll Mod) {
    return FastPow(val, Mod-2, Mod);
}

void Factorization(ll val) {
    while (val > 1LL) {
        ll p = d[val];
        if (p == 0)
            p = val;
        cnte[p]++;
        val /= p;
    }
}

ll CalAns() {
    ll ans = 1;
    for (auto it=cnte.begin(); it != cnte.end(); it++)
        ans = (ans*((*it).second+1LL))%Mod;
    return ans;
}

void Solve() {
    sort(Queries+1, Queries+1+t);
    ll val = 1;
    for (int i=1; i<=t; i++) {
        while (val <= Queries[i].first) {
            Factorization(val);
            val++;
        }
        ans[Queries[i].second] = CalAns();
    }
    for (int i=1; i<=t; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin>>t;
    ReadData();
    Solve();
    return 0;
}
