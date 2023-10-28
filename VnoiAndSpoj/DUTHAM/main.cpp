#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxM 100000
using namespace std;
typedef long long ll;
struct Edge {
    int u, v;
    ll w;
};
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
int n, m;
ll S[MaxN+5];
vector<Edge> e;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> S[i];
    for (int i=1; i<=m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        e.push_back({u, v, 2*w + S[u] + S[v]});
    }
}

bool CmpEdge(Edge a, Edge b) {
    return (a.w < b.w);
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    sort(e.begin(), e.end(), CmpEdge);
    for (Edge tmp: e)
        if (dsu.UnionSet(tmp.u, tmp.v))
            ans += tmp.w;
    return ans + S[1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BEAR.INP", "r", stdin);
    freopen("BEAR.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
