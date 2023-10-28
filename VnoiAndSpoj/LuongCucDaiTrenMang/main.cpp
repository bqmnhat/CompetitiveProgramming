#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
struct Edge {
    int u, v;
    ll flow, cap;
};
int n, m, s, t, iter[MaxN+1], level[MaxN+1];
vector<int> g[MaxN+1];
vector<Edge> edges;
const ll INF = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        edges.push_back({u, v, 0, c});
        g[u].push_back(edges.size()-1);
        edges.push_back({v, u, 0, 0});
        g[v].push_back(edges.size()-1);
    }
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
            if ((e.cap <= e.flow) || (level[e.v] != -1))
                continue;
            level[e.v] = level[u] + 1;
            q.push(e.v);
        }
    }
    return (level[t] != -1);
}

ll DFSAugment(int u, int t, ll PushedVal) {
    if (PushedVal == 0)
        return 0;
    if (u == t)
        return PushedVal;
    for (int &id = iter[u]; id<g[u].size(); id++) {
        int i = g[u][id];
        Edge e = edges[i];
        if ((e.cap <= e.flow) || (level[e.v] != level[u] + 1))
            continue;
        PushedVal = min(PushedVal, e.cap - e.flow);
        ll f = DFSAugment(e.v, t, PushedVal);
        if (f == 0)
            continue;
        edges[i].flow += f;
        edges[i^1].flow -= f;
        return f;
    }
    return 0;
}

ll Dinic(int s, int t) {
    ll NewFlow, MaxFlow = 0;
    while (BFSLevel(s,t)) {
        memset(iter, 0, sizeof(iter));
        while (NewFlow = DFSAugment(s, t, INF))
            MaxFlow += NewFlow;
    }
    return MaxFlow;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    ReadData();
    cout << Dinic(s, t);
    return 0;
}
