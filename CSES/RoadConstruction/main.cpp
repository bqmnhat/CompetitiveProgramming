#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n,m;
struct DSU {
    int par[MaxN+5], rank_depth[MaxN+5], Size[MaxN+5];
    void MakeSet(int u) {
        if (par[u] == 0) {
            par[u] = u;
            Size[u] = 1;
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
            Size[u] += Size[v];
            if (rank_depth[u] == rank_depth[v])
                rank_depth[u]++;
            return true;
        }
        return false;
    }
} dsu;

void Solve() {
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    int CurAns = 1, CurCCC = n;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        if (dsu.UnionSet(u, v))
            CurCCC--;
        CurAns = max(CurAns, dsu.Size[dsu.FindSet(u)]);
        cout << CurCCC << ' ' << CurAns << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
