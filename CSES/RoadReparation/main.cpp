#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, m;
vector<int> g[MaxN+5];
bool vis[MaxN+5];
struct Edge {
    int u, v;
    ll w;
} a[MaxN+5];
struct DSU {
    int par[MaxN+5], rank_depth[MaxN+5];
    void MakeSet(int u) {
        if (par[u] == 0) {
            par[u] = u;
            rank_depth[u] = 0;
        }
    }
    int FindSet(int u) {
        if (par[u] == 0)
            return -1;
        if (par[u] == u)
            return u;
        return (par[u] = FindSet(par[u]));
    }

    void UnionSet(int u, int v) { // connect v -> u
        u = FindSet(u);
        v = FindSet(v);
        if (u != v) {
            if (rank_depth[u] < rank_depth[v])
                swap(u, v);
            par[v] = u;
            if (rank_depth[u] == rank_depth[v])
                rank_depth[u]++;
        }
    }
} dsu;

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        g[a[i].u].push_back(a[i].v);
        g[a[i].v].push_back(a[i].u);
    }
}

void DFS(int u) {
    vis[u] = true;
    for (int v: g[u])
        if (!vis[v])
            DFS(v);
}

bool CmpEdge(Edge a, Edge b) {
    return (a.w < b.w);
}

void MSTCost() {
    int cntCCC = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            cntCCC++;
            if (cntCCC > 1) {
                cout << "IMPOSSIBLE";
                return;
            }
            DFS(i);
        }
    }
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    sort(a+1, a+1+m, CmpEdge);
    ll ans = 0;
    for (int i=1; i<=m; i++)  {
        Edge e = a[i];
        int u = dsu.FindSet(e.u), v = dsu.FindSet(e.v);
        if (u != v) {
            ans += e.w;
            dsu.UnionSet(e.u, e.v);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    MSTCost();
    return 0;
}
