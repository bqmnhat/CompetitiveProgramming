#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
int n, m, q, par[MaxN+1][21], tin[MaxN+1], tout[MaxN+1], counter = 0, l, height[MaxN+1];
ll MinW[MaxN+1][21];
vector<pii> g[MaxN+1];

void ReadData() {
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

void DFSPreprocess(int u, int p, int h) {
    counter++;
    height[u] = h;
    par[u][0] = p;
    tin[u] = counter;
    for (pii tmpv: g[u]) {
        int v = tmpv.first, w = tmpv.second;
        if (v != p) {
            MinW[v][0] = w;
            DFSPreprocess(v, u, h+1);
        }
    }
    counter++;
    tout[u] = counter;
}

void Preprocess() {
    l = ceil(log2(n));
    counter = 0;
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    for (int i=1; i<=n; i++)
        for (int j=0; j<=20; j++)
            MinW[i][j] = 1e18 + 7;
    DFSPreprocess(1, 1, 0);
    for (int j=1; j<=l; j++) {
        for (int i=1; i<=n; i++) {
            par[i][j] = par[par[i][j-1]][j-1];
            MinW[i][j] = min(MinW[i][j-1], MinW[par[i][j-1]][j-1]);
        }
    }
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    for (int k=l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

ll MinWBinaryLiftingUp(int u, int dist) {
    if (dist == 0)
        return 1e18 + 7;
    int cnt = 0;
    ll ans = 1e18+7;
    for (int k=l; k>=0; k--) {
        if (cnt + (1 << k) < dist) {
            ans = min(ans, MinW[u][k]);
            u = par[u][k];
            cnt += (1 << k);
        }
    }
    ans = min(ans, MinW[u][0]);
    return ans;
}

ll Solution(int a, int b) {
    int lcaAB = LCA(a, b);
    int LCAToA = abs(height[a] - height[lcaAB]);
    int LCAToB = abs(height[b] - height[lcaAB]);
    ll ans = min(MinWBinaryLiftingUp(a, LCAToA), MinWBinaryLiftingUp(b, LCAToB));
    return ans;
}

void Solve() {
    Preprocess();
    for (int i=1; i<=q; i++) {
        int u, v;
        cin >> u >> v;
        cout << Solution(u, v) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cin >> q;
    Solve();
    return 0;
}
