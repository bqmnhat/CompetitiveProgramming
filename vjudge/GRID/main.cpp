#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
#define MaxFac 2000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int t, m, n, Sieve[MaxFac+1];
ll k;
vector<pii> fac[MaxFac+1];

inline void MakeSieve() {
    for (int i=2; i*i<=MaxFac; i++)
        if (Sieve[i] == 0)
            for (int j=i; i*j<=MaxFac; j++)
                Sieve[i*j] = i;
}

inline void Factorization(int val) {
    unordered_map<int, int> mu;
    int tmpval = val;
    while (val > 1) {
        int p = Sieve[val];
        if (p == 0)
            p = val;
        mu[p]++;
        val /= p;
    }
    fac[tmpval].push_back(pii(1, 1));
    for (auto x = mu.begin(); x != mu.end(); x++)
        fac[tmpval].push_back((*x));
}

inline void FindAllFac() {
    for (int i=1; i<=MaxFac; i++)
        Factorization(i);
}

inline ll nCk(int n, int k, ll Mod) {
    vector<int> cnt(MaxFac+1, 0);
    int tmp = n-k;
    for (int i=1; i<=n; i++) {
        for (pii x: fac[i]) {
            cnt[x.first] += x.second;
            if (i <= tmp)
                cnt[x.first] -= x.second;
            if (i <= k)
                cnt[x.first] -= x.second;
        }
    }
    ll ans = 1;
    for (int i=2; i<=MaxFac; i++) {
        ll tmpx = 1;
        for (int j=1; j<=cnt[i]; j++)
            tmpx = (tmpx*1LL*i)%Mod;
        ans = (ans*1LL*tmpx)%Mod;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> m >> n >> k;
        cout << nCk(m+n, n, k) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    FindAllFac();
    cin >> t;
    Solve();
    return 0;
}
