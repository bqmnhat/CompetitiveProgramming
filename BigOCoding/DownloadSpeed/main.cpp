#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
using namespace std;
typedef long long ll;
struct Edge {
    int u, v;
    ll cap, flow;
};
int n, m, iter[MaxN+1], level[MaxN+1];
vector<Edge> edges;
vector<int> g[MaxN+1];
const ll INF = 1e18 + 7;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        g[u].push_back(edges.size()-1);
        edges.push_back({v, u, 0});
        g[v].push_back(edges.size()-1);
    }
}

bool BFS(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i: g[u]) {
            Edge e = edges[i];
            if (level[e.v] != -1)
                continue;
            if (e.cap - e.flow <= 0)
                continue;
            level[e.v] = level[u] + 1;
            q.push(e.v);
        }
    }
    return (level[t] != -1);
}

ll DFSNewFlow(int u, int t, ll PushedVal) {
    if (PushedVal == 0)
        return 0;
    if (u == t)
        return PushedVal;
    for (int &i = iter[u]; i < g[u].size(); i++) {
        int id = g[u][i];
        int v = edges[id].v;
        if (level[v] != level[u] + 1)
            continue;
        if (edges[id].cap <= edges[id].flow)
            continue;
        ll f = min(PushedVal, edges[id].cap - edges[id].flow);
        f = DFSNewFlow(v, t, f);
        if (f == 0)
            continue;
        edges[id].flow += f;
        edges[id^1].flow -= f;
        return f;
    }
    return 0;
}

ll Dinic(int s, int t) {
    ll NewFlow, MaxFlow = 0;
    while (BFS(s, t)) {
        memset(iter, 0, sizeof(iter));
        while (NewFlow = DFSNewFlow(s, t, INF))
            MaxFlow += NewFlow;
    }
    return MaxFlow;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Dinic(1, n);
    return 0;
}
