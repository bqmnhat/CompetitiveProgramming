#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, par[MaxN+1];
ll dpD[MaxN+1], dpU[MaxN+1], Mod;
vector<int> g[MaxN+1];
vector<ll> pref[MaxN+1], suf[MaxN+1];
map<int, int> id[MaxN+1];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSDown(int u, int p) {
    par[u] = p;
    dpD[u] = 1;
    int cnt = 0;
    pref[u].assign(g[u].size()+2, 1);
    suf[u].assign(g[u].size()+2, 1);
    vector<int> tmp;
    tmp.push_back(-1);
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFSDown(v, u);
        cnt++;
        id[u][v] = cnt;
        pref[u][cnt] = (pref[u][cnt-1]*dpD[v])%Mod;
        dpD[u] = (dpD[u] * dpD[v])%Mod;
        tmp.push_back(v);
    }
    for (int i = tmp.size() - 1; i>=1; i--) {
        int v = tmp[i];
        suf[u][i] = (suf[u][i+1]*dpD[v])%Mod;
    }
    dpD[u] = (dpD[u] + 1)%Mod;
}

void DFSUp(int u, int p) {
    if (p == -1)
        dpU[u] = 1;
    else {
        int idInP = id[p][u];
        dpU[u] = ((1LL%Mod) + ((dpU[p]*pref[p][idInP-1])%Mod*suf[p][idInP+1])%Mod);
    }
    for (int v: g[u])
        if (v != p)
            DFSUp(v, u);
}

void Solve() {
    for (int i=1; i<=n; i++) {
        ll ans = (((dpD[i] - 1LL + Mod)%Mod)*dpU[i])%Mod;
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Mod;
    ReadData();
    DFSDown(1, -1);
    DFSUp(1, -1);
    Solve();
    return 0;
}
