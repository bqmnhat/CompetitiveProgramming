#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxM 100000
using namespace std;
typedef long long ll;
typedef pair<int, ll> pll;
struct Edge {
    int u, v;
    ll w;
};

struct Query {
    int u, v, id;
    ll k, Ans;
} Q[MaxM+1];

int t, n, m, tin[MaxN+1], tout[MaxN+1], par[MaxN+1][20], counter = 0, l;
vector<Edge> edges;
vector<int> g[MaxN+1];
ll st[8*MaxN+1];

void ReadGraph() {
    for (int i=1; i<=n; i++)
        g[i].clear();
    int u, v;
    ll w;
    for (int i=1; i<n; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void ReadQueries() {
    for (int i=1; i<=m; i++) {
        cin >> Q[i].u >> Q[i].v >> Q[i].k;
        Q[i].id = i;
    }
}

void DFSPreprocess(int u, int p) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    for (auto v: g[u])
        if (v != p)
            DFSPreprocess(v, u);
    counter++;
    tout[u] = counter;
}

void Preprocess() {
    counter = 0;
    for(int i=1; i<=n; i++)
        tin[i] = tout[i] = 0;
    DFSPreprocess(1, 1);
    l = ceil(log2(n));
    for (int k=1; k<=l; k++)
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
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

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] ^= val;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2]^st[v*2+1];
    }
}

ll XorQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return (XorQuery(v*2, tl, tm, l, r) ^ (XorQuery(v*2+1, tm+1, tr, l, r)));
}

bool CmpEdges(Edge a, Edge b) {
    return (a.w < b.w);
}

bool CmpQK(Query a, Query b) {
    return (a.k < b.k);
}

bool CmpQId(Query a, Query b) {
    return (a.id < b.id);
}

void SolveTestCase() {
    Preprocess();
    int i = 0;
    sort(edges.begin(), edges.end(), CmpEdges);
    sort(Q+1, Q+1+m, CmpQK);
    for (int i=1; i<=m; i++) {
        ll CurK = Q[i].k;
        int u = Q[i].u, v = Q[i].v;
        while ((edges[i].w <= CurK) && (i < edges.size())) {
            int p;
            if (par[edges[i].u][0] == edges[i].v)
                p = edges[i].v;
            else
                p = edges[i].u;
            UpdateSt(1, 1, 2*n, tin[p], edges[i].w);
            UpdateSt(1, 1, 2*n, tout[p], edges[i].w);
        }
        int lca = LCA(u, v);
        Q[i].Ans = (XorQuery(1, 1, 2*n, 1, tin[u]) ^ XorQuery(1, 1, 2*n, 1, tin[v]) ^ XorQuery(1, 1, 2*n, 1, tin[lca]));
    }
    sort(Q+1, Q+1+m, CmpQId);
    for (int i=1; i<=m; i++)
        cout << Q[i].Ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    cin >> n;
    ReadGraph();
    cin >> m;
    ReadQueries();
    SolveTestCase();
    return 0;
}
