#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, q, tin[MaxN+1], tout[MaxN+1], counter = 0, l, par[MaxN+1][20];
vector<pii> g[MaxN+1];
ll d[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        g[i].clear();
    for (int u = 1; u<n; u++) {
        int v, w;
        cin >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

void DFS(int u, int p, ll droot) {
    counter++;
    tin[u] = counter;
    d[u] = droot;
    par[u][0] = p;
    for (auto v: g[u])
        if (v.first != p)
            DFS(v.first, u, droot + 1LL*v.second);
    counter++;
    tout[u] = counter;
}

void PreProcess() {
    counter = 0;
    l = ceil(log2(n));
    DFS(0, 0, 0);
    for (int k=1; k<=l; k++)
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
}

bool IsAncestor(int u, int v) {
    return ((tin[u] <= tin[v]) && (tin[v] <= tout[u]));
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

ll Query(int s, int t) {
    int lca = LCA(s, t);
    return((d[s] - d[lca]) + (d[t] - d[lca]));
}

void SolveTestCases() {
    ReadData();
    PreProcess();
    cin >> q;
    int s, t;
    for (int i=1; i<=q; i++) {
        cin >> s >> t;
        cout << Query(s, t) << ' ';
    }
    cout << '\n';
}

void Solve() {
    while ((cin >> n) && (n != 0))
        SolveTestCases();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
