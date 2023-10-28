#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e9;
int n, m;
ll Sum = 0;
vector<int> g[MaxN+5];
struct DSU {
    int par[MaxN+5], rank_depth[MaxN+5];
    ll Size[MaxN+5];
    void MakeSet(int u) {
        if (par[u] == 0) {
            par[u] = u;
            rank_depth[u] = 0;
            Size[u] = 1;
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
struct Edge {
    int u, v;
    ll w;
} a[MaxN+5];

void Init() {
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        Sum += a[i].w;
        g[a[i].u].push_back(a[i].v);
        g[a[i].v].push_back(a[i].u);
    }
}

bool CmpEdge(Edge a, Edge b) {
    return a.w > b.w;
}

ll Solution() {
    Init();
    sort(a+1, a+1+m, CmpEdge);
    ll ans = 0;
    for (int i = 1; i<=m; i++) {
        Edge e = a[i];
        ll SizeU = dsu.Size[dsu.FindSet(e.u)];
        ll SizeV = dsu.Size[dsu.FindSet(e.v)];
        ll Addition = ((Sum*SizeU)%Mod * SizeV)%Mod;
        if (dsu.UnionSet(e.u, e.v))
            ans = (ans + Addition)%Mod;
        Sum -= e.w;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
