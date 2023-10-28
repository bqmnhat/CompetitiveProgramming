#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, k, cnt[MaxN+1], ans[MaxN+1], tin[MaxN+1], tout[MaxN+1], counter = 0, par[MaxN+1][20], l, q;
vector<int> g[MaxN+1];
vector<pii> Edges;

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        Edges.push_back(pii(u, v));
    }
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    for (auto v: g[u])
        if (v != p)
            DFS(v, u);
    counter++;
    tout[u] = counter;
}

void PreProcess() {
    counter = 0;
    l = ceil(log2(n));
    DFS(1, 1);
    for (int k=1; k<=l; k++)
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
}

bool IsAncestor(int Anc, int v) {
    return ((tin[Anc] <= tin[v]) && (tin[v] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    for (int k = l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

void Query(int u, int v) {
    int lca = LCA(u, v), k = l;
    cnt[u]++;
    cnt[v]++;
    cnt[lca] -= 2;
}

int DFSToCount(int u, int p) {
    for (auto v: g[u])
        if (v != p)
            cnt[u] += DFSToCount(v, u);
    return cnt[u];
}

void PrintAns() {
    DFSToCount(1, 1);
    int tmpn = Edges.size();
    for (int i=0; i<tmpn; i++) {
        pii tmp = Edges[i];
        if (par[tmp.first][0] == tmp.second)
            ans[i] = cnt[tmp.first];
        else
            ans[i] = cnt[tmp.second];
        cout << ans[i] << ' ';
    }
}

void Solve() {
    PreProcess();
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        Query(a, b);
    }
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
