#include <iostream>
#include <bits/stdc++.h>
#define MaxN 405
using namespace std;
typedef long long ll;
struct Edge {
    int u, v;
    ll flow, cap;
};
int n, iter[MaxN+1], level[MaxN+1], pre[MaxN+1];
ll dist[MaxN+1], c[MaxN+1][MaxN+1];
bool InQ[MaxN+1];
vector<Edge> edges;
vector<int> g[MaxN+1];
queue<int> q;
const ll INF = 1e15 + 7;

void AddEdge(int u, int v, ll c) {
    edges.push_back({u, v, 0, c});
    g[u].push_back(edges.size()-1);
    edges.push_back({v, u, 0, 0});
    g[v].push_back(edges.size()-1);
}

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> c[i][j];
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
        int f = min(PushedVal, edges[id].cap - edges[id].flow);
        f = DFSNewFlow(v, t, f);
        if (f == 0)
            continue;
        edges[id].flow += f;
        edges[id^1].flow -= f;
        return f;
    }
    return 0;
}

bool Dinic(int s, int t) {
    ll NewFlow, MaxFlow = 0;
    while (BFS(s, t)) {
        memset(iter, 0, sizeof(iter));
        while (NewFlow = DFSNewFlow(s, t, INF))
            MaxFlow += NewFlow;
    }
    return (MaxFlow == n);
}

bool Check(ll val) {
    for (int i=0; i<=2*n+1; i++)
        g[i].clear();
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (c[i][j] <= val)
                AddEdge(i, j+n, 1);
    for (int i=1; i<=n; i++) {
        AddEdge(0, i, 1);
        AddEdge(i+n, 2*n+1, 1);
    }
    return (Dinic(0, 2*n+1));
}

ll BinSearch() {
    ll lo = 0, hi = 1e18, ans;
    while (lo <= hi) {
        ll mid = ((lo + hi) >> 1LL);
        if (Check(mid)) {
            ans = mid;
            hi = mid - 1LL;
        }
        else
            lo = mid + 1LL;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << BinSearch();
    return 0;
}
