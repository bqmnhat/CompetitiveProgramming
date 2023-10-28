#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, q, n, m;
ll e, h[MaxN+5];
bool ans[MaxN+5];
vector<pii> Edges;
struct Qry {
    int a, b, id;
    ll e;
};
vector<Qry> Querries;
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
        return par[u] = FindSet(par[u]);
    }
    bool UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v) {
            if (rank_depth[u] < rank_depth[v])
                swap(u, v);
            par[v] = u;
            if (rank_depth[u] == rank_depth[v])
                rank_depth[u]++;
            return true;
        }
        return false;
    }
} dsu;

void ReadData() {
    Edges.clear();
    Querries.clear();
    for (int i=1; i<=n; i++)
        cin >> h[i];
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        pii ed;
        if (h[u] > h[v]) {
            ed.first = u;
            ed.second = v;
        }
        else {
            ed.first = v;
            ed.second = u;
        }
        Edges.push_back(ed);
    }
    int a, b, e;
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> a >> b >> e;
        Querries.push_back({a, b, i, e});
    }
}

bool CmpQry(Qry x, Qry y) {
    return ((h[x.a] + x.e) < (h[y.a] + y.e));
}

bool CmpQryID(Qry x, Qry y) {
    return (x.id < y.id);
}

bool CmpEdges(pii a, pii b) {
    return (h[a.first] < h[b.first]);
}

void SolveTestCase() {
    sort(Edges.begin(), Edges.end(), CmpEdges);
    sort(Querries.begin(), Querries.end(), CmpQry);
    memset(dsu.par, 0, sizeof(dsu.par));
    memset(ans, false, sizeof(ans));
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    int e_it = 0;
    for (Qry q: Querries) {
        int a = q.a, b = q.b, id = q.id;
        ll e = q.e;
        while ((e_it < Edges.size()) && (h[Edges[e_it].first] <= (h[a] + e))) {
            dsu.UnionSet(Edges[e_it].first, Edges[e_it].second);
            e_it++;
        }
        if (dsu.FindSet(a) == dsu.FindSet(b))
            ans[id] = true;
        else
            ans[id] = false;
    }
    for (int i=1; i<=q; i++) {
        if (ans[i] == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        ReadData();
        SolveTestCase();
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
