#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, k;
struct Edge {
    int u,v,id;
};
vector<Edge> edge[2];
vector<int> ans;
struct DSU {
    int parent[100001];
    void MakeSet(int u) {
        if (parent[u] == 0)
            parent[u] = u;
    }
    int FindSet(int u) {
        if (parent[u] == 0)
            return -1;
        if (parent[u] == u)
            return u;
        return (parent[u] = FindSet(parent[u]));
    }
    void UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v)
            parent[v] = u;
    }
}dsu0, dsu1, Tree;

void ReadGraph() {
    int u,v,c;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> c;
        edge[c].push_back({u,v,i});
    }
}

void Init() {
    for (int i=1; i<=n; i++) {
        dsu0.MakeSet(i);
        dsu1.MakeSet(i);
        Tree.MakeSet(i);
    }
}

int Build0Forest() {
    int CntTree = 0;
    for (Edge e: edge[0]) {
        int u = e.u, v = e.v;
        dsu0.UnionSet(u, v);
    }
    for (int i=1; i<=n; i++)
        if (dsu0.parent[i] == i)
            CntTree++;
    return CntTree;
}

void Add1Edges() {
    for (Edge e : edge[1]) {
        int  u = e.u, v = e.v, id = e.id;
        if ((dsu0.FindSet(u) != dsu0.FindSet(v)) && (Tree.FindSet(u) != Tree.FindSet(v))) {
            Tree.UnionSet(u,v);
            dsu1.UnionSet(u,v);
            dsu0.UnionSet(u,v);
            ans.push_back(id);
        }
        if (ans.size() == k)
            return;
    }
    for (Edge e: edge[1]) {
        int u = e.u, v = e.v, id = e.id;
        if (dsu1.FindSet(u) != dsu1.FindSet(v)) {
            Tree.UnionSet(u,v);
            dsu1.UnionSet(u,v);
            ans.push_back(id);
        }
        if (ans.size() == k)
            return;
    }
}

void Add0Edges() {
    for (Edge e: edge[0]) {
        int u = e.u, v = e.v, id = e.id;
        if (Tree.FindSet(u) != Tree.FindSet(v)) {
            Tree.UnionSet(u,v);
            ans.push_back(id);
        }
    }
}

void Solve() {
    Init();
    int CntTree = Build0Forest();
    if (CntTree > k+1) {
        cout << "-1";
        return;
    }
    Add1Edges();
    if (ans.size() < k) {
        cout << "-1";
        return;
    }
    Add0Edges();
    for (int x: ans)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ROADS.INP", "r", stdin);
    freopen("ROADS.OUT", "w", stdout);
    cin >> n >> m >> k;
    ReadGraph();
    Solve();
    return 0;
}
