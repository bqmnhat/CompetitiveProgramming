#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
struct Edge {
    int u, v, id;
    ll w;
};
struct DSU {
    int par[MaxN+1];
    DSU() {
        memset(par, 0, sizeof(par));
    }
    void FillDSU(int l, int r) {
        for (int i=l; i<=r; i++)
            par[i] = i;
    }
    void MakeSet(int u) {
        if (par[u] == 0)
            par[u] =u;
    };
    int FindSet(int u) {
        if (par[u] == 0)
            return -1;
        if (par[u] == u)
            return u;
        return (par[u] = FindSet(par[u]));
    }
    bool UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u == v)
            return false;
        else {
            par[v] = u;
            return true;
        }
    }
} dsu;
int n, m, counter, tin[MaxN+1], tout[MaxN+1], par[MaxN+1][21];
vector<pii> g[MaxN+1], MST[MaxN+1];
pii OrderBL[MaxN+1][21]; // Used for binary lifting to find the minimum ans second minimum edge
vector<Edge> edges;
bool InMST[MaxN+1];
ll MSTSize;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
        edges.push_back({u, v, i-1, w});
    }
}

bool CmpEdgeViaW(Edge a, Edge b) {
    return (a.w < b.w);
}

bool CmpEdgeViaId(Edge a, Edge b) {
    return (a.id < b.id);
}

void Kruskal() {
    dsu.FillDSU(1, n);
    MSTSize = 0;
    sort(edges.begin(), edges.end(), CmpEdgeViaW);
    for (int i = 0; i<m; i++) {
        Edge tmp = edges[i];
        int u = tmp.u, v = tmp.v;
        ll w = tmp.w;
        if (dsu.UnionSet(u, v)) {
            InMST[tmp.id] = true;
            MSTSize += w;
            MST[u].push_back(pii(v, w));
            MST[v].push_back(pii(u, w));
        }
    }
    sort(edges.begin(), edges.end(), CmpEdgeViaId);
}

void DFS(int u, int p, ll d) { // DFS on MST to identify: 1. Euler tour; 2. parent => LCA and Binary Lifting
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    OrderBL[u][0] = pii(d, -1);
    for (pii tmpv: MST[u]) {
        int v = tmpv.first;
        ll w = tmpv.second;
        if (v == p)
            continue;
        DFS(v, u, w);
    }
    tout[u] = counter;
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

pii CombineOrder(pii a, pii b) {
    vector<ll> tmp = {a.first, a.second, b.first, b.second};
    ll TopOne = -2, TopTwo = -3;
    for (ll x: tmp) {
        if (x > TopOne) {
            TopTwo = TopOne;
            TopOne = x;
        }
        else if ((x > TopTwo) && (x < TopOne))
            TopTwo = x;
    }
    return pii(TopOne, TopTwo);
}

void Preprocess() { // After MST is built
    counter = 0;
    DFS(1, 1, -1);
    int l = 20;
    for (int j=1; j<=l; j++) {
        for (int i=1; i<=n; i++) {
            int p = par[i][j-1];
            par[i][j] = par[p][j-1];
            OrderBL[i][j] = CombineOrder(OrderBL[i][j-1], OrderBL[p][j-1]);
        }
    }
}

pii OrderFromAToB(int A, int B) { // B is ancestor of A
    int l = 20;
    pii ans = {-1, -1};
    for (int i=l; i>=0; i--) {
        if (!IsAncestor(par[A][i], B)) {
            ans = CombineOrder(ans, OrderBL[A][i]);
            A = par[A][i];
        }
    }
    ans = CombineOrder(ans, OrderBL[A][0]);
    return ans;
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    int l = 20;
    for (int i = l; i>=0; i--)
        if (!IsAncestor(par[u][i], v))
            u = par[u][i];
    return par[u][0];
}

void Solve() {
    for (int i=0; i<m; i++) {
        Edge tmp = edges[i];
        int u = tmp.u, v = tmp.v;
        ll w = tmp.w;
        if (InMST[i]) {
            cout << MSTSize << '\n';
            continue;
        }
        int lca = LCA(u, v);
        pii MaxEdgesInMST;
        if (lca == u)
            MaxEdgesInMST = OrderFromAToB(v, lca);
        else if (lca == v)
            MaxEdgesInMST = OrderFromAToB(u, lca);
        else
            MaxEdgesInMST = CombineOrder(OrderFromAToB(u, lca), OrderFromAToB(v, lca));
        ll ans = MSTSize - MaxEdgesInMST.first + w;
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Kruskal();
    Preprocess();
    Solve();
    return 0;
}
