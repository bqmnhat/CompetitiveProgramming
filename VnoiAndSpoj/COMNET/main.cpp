#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxM 1000000
using namespace std;
typedef long long ll;
int t, n, m, q, k, s[MaxM+1];
struct Edge {
    int u, v;
    ll w;
};
vector<Edge> edges;
struct DSU {
    int par[MaxN+1];
    void Init(int n) {
        for (int i=1; i<=n; i++)
            par[i] = i;
    }
    void MakeSet(int v) {
        if (par[v] == 0)
            par[v] = v;
    }
    int FindSet(int v) {
        if (par[v] == 0)
            return -1;
        if (par[v] == v)
            return v;
        return (par[v] = FindSet(par[v]));
    }
    bool UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v) {
            par[u] = v;
            return true;
        }
        return false;
    }
} dsu;

void ReadData() {
    edges.clear();
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
}

void SolveTestCase() {
    for (int i=1; i<=q; i++) {
        cin >> k;
        int sj, t;
        ll c;
        cin >> sj;
        memset(s, 0, sizeof(s));
        for (int j=1; j<=sj; j++) {
            cin >> t >> c;
            s[t-1] = c;
        }
        Edge cur = edges[k-1];
        if (s[k-1] > 0)
            cur.w = s[k-1];
        dsu.Init(n);
        for (int i = 0; i<(int)edges.size(); i++) {
            Edge tmp = edges[i];
            if (s[i] > 0)
                tmp.w = s[i];
            if (tmp.w < cur.w)
                dsu.UnionSet(tmp.u, tmp.v);
        }
        if (dsu.FindSet(cur.u) == dsu.FindSet(cur.v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> q;
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
