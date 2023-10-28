#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
int n, m, iter[2*MaxN+1], level[2*MaxN+1];
struct Edge {
    int u, v, flow, cap;
};
vector<int> g[2*MaxN+1];
vector<Edge> edges;
const int INF = 1e9 + 7;

void Init() {
    for (int i=1; i<=2*n; i++)
        g[i].clear();
    edges.clear();
}

void AddEdges(int u, int v, int c) {
    edges.push_back({u+n, v, 0, c});
    g[u+n].push_back(edges.size()-1);
    edges.push_back({v, u+n, 0, 0});
    g[v].push_back(edges.size()-1);
    edges.push_back({v+n, u, 0, c});
    g[v+n].push_back(edges.size()-1);
    edges.push_back({u, v+n, 0, 0});
    g[u].push_back(edges.size()-1);
}

void AddVerTexEdges(int id, int c) {
    edges.push_back({id, id+n, 0, c});
    g[id].push_back(edges.size()-1);
    edges.push_back({id+n, id, 0, 0});
    g[id+n].push_back(edges.size()-1);
    edges.push_back({id+n, id, 0, c});
    g[id+n].push_back(edges.size()-1);
    edges.push_back({id, id+n, 0, 0});
    g[id].push_back(edges.size()-1);
}

void ReadData() {
    for (int i=1; i<=n-2; i++) {
        int id, c;
        cin >> id >> c;
        AddVerTexEdges(id, c);
    }
    for (int i=1; i<=m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        AddEdges(u, v, c);
    }
    AddVerTexEdges(1, INF);
    AddVerTexEdges(n, INF);
}

bool BFSLevel(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i: g[u]) {
            Edge e = edges[i];
            if ((level[e.v] != -1) || (e.cap <= e.flow))
                continue;
            level[e.v] = level[u] + 1;
            q.push(e.v);
        }
    }
    return (level[t] != -1);
}

int DFS(int u, int t, int PushedVal) {
    if (PushedVal == 0)
        return 0;
    if (u == t)
        return PushedVal;
    for (int &i = iter[u]; i<g[u].size(); i++) {
        int id = g[u][i];
        Edge e = edges[id];
        if ((level[e.v] != level[u] + 1) || (e.cap <= e.flow))
            continue;
        int f = min(PushedVal, e.cap - e.flow);
        f = DFS(e.v, t, f);
        if (f == 0)
            continue;
        edges[id].flow += f;
        edges[id^1].flow -= f;
        return f;
    }
    return 0;
}

int Dinic(int s, int t) {
    int NewFlow, MaxFlow = 0;
    while (BFSLevel(s, t)) {
        memset(iter, 0, sizeof(iter));
        while (NewFlow = DFS(s, t, INF))
            MaxFlow += NewFlow;
    }
    return MaxFlow;
}

void Solve() {
    while ((cin >> n >> m) && ((n != 0) || (m != 0))) {
        Init();
        ReadData();
        cout << Dinic(1, n) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
