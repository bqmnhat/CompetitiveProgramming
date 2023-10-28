#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int n, q, h[MaxN+1], par[MaxN+1][20], tin[MaxN+1], tout[MaxN+1], counter;
vector<int> g[MaxN+1];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p, int height) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    h[u] = height;
    for (int v: g[u])
        if (v != p)
            DFS(v, u, height + 1);
    tout[u] = counter;
}

void Preprocess() {
    counter = 0;
    DFS(1, 1, 0);
    int l = log2(n);
    for (int j=1; j<=l; j++)
        for (int i=1; i<=n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    int l = log2(n);
    for (int i=l; i>=0; i--)
        if (!IsAncestor(par[u][i], v))
            u = par[u][i];
    return par[u][0];
}

void Solve() {
    int a, b;
    for (int i=1; i<=q; i++) {
        cin >> a >> b;
        if (h[a] < h[b])
            cout << "NO\n";
        else
            cout << "YES " << LCA(a, b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Preprocess();
    cin >> q;
    Solve();
    return 0;
}
