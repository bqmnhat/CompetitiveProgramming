#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct Edge {
    int u, v, w;
};
int n, m, child[200001];
long long ans[2000002];
Edge edges[200001];
vector<pii> g[100001];

struct DSU {
    public:
        int parent[100001], rank_depth[100001];
        void MakeSet(int u) {
            parent[u] = u;
            rank_depth[u] = 0;
        }
        int FindSet(int u) {
            if (u == parent[u])
                return u;
            return (parent[u] = FindSet(parent[u]));
        }
        bool UnionSet(int u, int v) {
            u = FindSet(u);
            v = FindSet(v);
            if (u == v) return false;
            if (rank_depth[u] > rank_depth[v])
                parent[v] = u;
            else if (rank_depth[u] < rank_depth[v])
                parent[u] = v;
            else {
                parent[v] = u;
                rank_depth[u]++;
            }
            return true;
        }
}dsu;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
}

bool CmpEdge(Edge a, Edge b) {
    return (a.w < b.w);
}

void DFS(int u, int par) {
    child[u] = 1;
    for (auto i: g[u]) {
        int v = i.first, w = i.second;
        if (v != par) {
            DFS(v, u);
            ans[w] += 1LL * child[v] * (n - child[v]);
            child[u] += child[v];
        }
    }
}

void Kruskal() {
    int MaxW = 0;
    sort(edges+1, edges+1+m, CmpEdge);
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    for (int u,v,w, i = 1; i<=m; i++) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (dsu.UnionSet(u,v)) {
            g[u].push_back(pii(v, w));
            g[v].push_back(pii(u, w));
            MaxW = max(MaxW, w);
        }
    }
    DFS(1, 0);
    for (int bit = 0; bit < MaxW; bit++) {
        ans[bit+1] += ans[bit]/2;
        ans[bit] %= 2;
    }
    while (ans[MaxW] > 1) {
        ans[MaxW  + 1] += ans[MaxW]/2;
        ans[MaxW] %= 2;
        MaxW++;
    }
    for (int bit = MaxW; bit >= 0; bit--)
        cout << ans[bit];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Kruskal();
    return 0;
}
