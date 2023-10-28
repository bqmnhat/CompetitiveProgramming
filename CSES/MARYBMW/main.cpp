#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, m, t;
vector<int> g[MaxN+5];
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
    void UnionSet(int u, int v) {
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
struct Edge {
    int u, v;
    ll w;
} a[MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        g[a[i].u].push_back(a[i].v);
        g[a[i].v].push_back(a[i].u);
    }
}

bool CmpEdge(Edge a, Edge b) {
    return (a.w > b.w);
}

void Init() {
    for (int i=1; i<=n; i++) {
        dsu.par[i] = i;
        dsu.rank_depth[i] = 0;
        g[i].clear();
    }
}

ll Solution() {
    sort(a+1, a+1+m, CmpEdge);
    for (int i=1; i<=m; i++) {
        Edge e = a[i];
        dsu.UnionSet(e.u, e.v);
        if (dsu.FindSet(1) == dsu.FindSet(n))
            return e.w;
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
