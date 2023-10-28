#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
const int MAX_LOG = 18;
int n, m, tin[MaxN+5], tout[MaxN+5], ans[MaxN+5], counter, par[MaxN+5][MAX_LOG];
vector<int> g[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSPreprocess(int u, int p) {
    tin[u] = ++counter;
    par[u][0] = p;
    for (int v: g[u])
        if (v != p)
            DFSPreprocess(v, u);

    tout[u] = ++counter;
}

void Preprocess() {
    counter = 0;
    DFSPreprocess(1, 1);
    int l = log2(n);

    for (int k=1; k<=l; k++)
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
}

bool IsAncestor(int u, int v) {
    return ((tin[u] <= tin[v]) && (tin[v] <= tout[u]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v)) return u;
    if (IsAncestor(v, u)) return v;

    int l = log2(n);
    for (int k=l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

void DFSAns(int u, int p) {
    for (int v: g[u]) {
        if (v != p) {
            DFSAns(v, u);
            ans[u] += ans[v];
        }
    }
}

void Solve() {
    counter = 0;
    Preprocess();
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        int lca = LCA(a, b);
        ans[a]++;
        ans[b]++;
        ans[lca]--;
        if (lca != 1)
            ans[par[lca][0]]--;
    }
    DFSAns(1, 1);
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
