#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5001
using namespace std;
int n, l, counter, par[MaxN+1][21], tin[MaxN+1], tout[MaxN+1];
vector<int> g[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=n;i++)
        g[i].clear();
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    for (auto v: g[u])
        if (p != v)
            DFS(v, u);
    counter++;
    tout[u] = counter;
}

void PreProcess() {
    counter = 0;
    l = ceil(log2(n));
    DFS(1, 1);
    for (int k=1; k<=l; k++) {
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
    }
}

bool IsAncestor(int Anc, int v) {
    return ((tin[Anc] <= tin[v]) && (tin[v] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v)) return u;
    if (IsAncestor(v, u)) return v;
    for (int k=l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

void SolveTestCase(int u, int v) {
    int lenu = 0, lenv = 0, lca = LCA(u, v);
    vector<int> pu, pv;
    pu.clear();
    pv.clear();
    while (u != lca) {
        pu.push_back(u);
        u = par[u][0];
        lenu++;
    }
    pu.push_back(lca);
    while (v != lca) {
        pv.push_back(v);
        v = par[v][0];
        lenv++;
    }
    pv.push_back(lca);
    int mid1, mid2, midlen = (lenu + lenv)/2;
    if (lenu > lenv) {
        mid1 = pu[midlen];
        mid2 = pu[midlen+1];
    }
    else {
        mid1 = pv[midlen];
        mid2 = pv[midlen+1];
    }
    if ((lenu + lenv)%2 == 0)
        cout << "The fleas meet at " << mid1 << ".\n";
    else
        cout << "The fleas jump forever between " << min(mid1,mid2) << " and " << max(mid1, mid2) << ".\n";
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadGraph();
        counter = 0;
        PreProcess();
        int q;
        cin >> q;
        for (int i=1; i<=q; i++) {
            int u, v;
            cin >> u >> v;
            SolveTestCase(u, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
