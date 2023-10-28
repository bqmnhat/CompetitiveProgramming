#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Edge {
    int u,v, weight;
    bool operator < (Edge const& other) {
        return (weight < other.weight);
    }
} edge[1000001];
struct DSU {
    public:
        int parent[1000001], rank_depth[1000001];
        void make_set(int v) {
            parent[v] = v;
            rank_depth[v] = 0;
        }
        int FindSet(int u) {
            if (parent[u] == u)
                return u;
            return (parent[u] = FindSet(parent[u]));
        }
        void union_set(int u, int v) {
            u = FindSet(u);
            v = FindSet(v);
            if (u != v) {
                if (rank_depth[u] < rank_depth[v])
                    swap(u,v);
                parent[v] = u;
                if (rank_depth[u] == rank_depth[v])
                    rank_depth[u]++;
            }
        }
} g;

void ReadEdges() {
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].weight = w;
    }
}

int Kruskal() {
    int cost = 0;
    vector<Edge> MST;
    for (int i=1; i<=n; i++)
        g.make_set(i);
    sort(edge+1, edge+1+m);
    for (int i=1; i<=m; i++) {
        Edge e = edge[i];
        if (g.FindSet(e.u) != g.FindSet(e.v)) {
            cost += e.weight;
            MST.push_back(e);
            g.union_set(e.u, e.v);
        }
    }
    return cost;
}

void Solve() {
    ReadEdges();
    int ans = Kruskal();
    cout << ans;
}

int main()
{
    cin >> n >> m;
    Solve();
    return 0;
}
