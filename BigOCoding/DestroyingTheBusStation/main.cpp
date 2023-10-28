#include <iostream>
#include <bits/stdc++.h>
#define MaxN 55
using namespace std;
typedef pair<int, int> pii;
int n, m, k, dist[MaxN+1][MaxN+1], iter[2*MaxN+1], level[2*MaxN+1];
struct Edge {
    int u, v, flow, cap;
};
vector<int> g[MaxN+1], NewG[2*MaxN+1];
vector<Edge> edges, NewEdges;
const int INF = 1e4 + 7;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, 0, 1});
        g[u].push_back(edges.size()-1);
        edges.push_back({v, u, 0, 0});
        g[v].push_back(edges.size()-1);
    }
}

void Init() {
    edges.clear();
    NewEdges.clear();
    for (int i=1; i<=n; i++)
        g[i].clear();
    for (int i=1; i<=2*n; i++) {
        g[i].clear();
        NewG[i].clear();
    }
}

void Dijkstra(int src) {
    for (int i=1; i<=n; i++)
        dist[src][i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, src));
    dist[src][src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second, du = pq.top().first;
        pq.pop();
        if (du > dist[src][u])
            continue;
        for (int i: g[u]) {
            Edge e = edges[i];
            int v = e.v;
            if (dist[src][u] + 1 < dist[src][v]) {
                dist[src][v] = dist[src][u] + 1;
                pq.push(pii(dist[src][v], e.v));
            }
        }
    }
}

void MakeG() {
    for (int i=1; i<=n; i++)
        Dijkstra(i);
    for (Edge e: edges) {
        if (e.cap == 0)
            continue;
        if (dist[1][e.u] + dist[e.v][n] + 1 > k)
            continue;
        NewEdges.push_back({e.u+n, e.v, 0, INF});
        NewG[e.u + n].push_back(NewEdges.size()-1);
        NewEdges.push_back({e.v, e.u+n, 0, 0});
        NewG[e.v].push_back(NewEdges.size()-1);
    }
    for (int i=1; i<=n; i++) {
        int cap;
        cap = 1;
        if ((i == 1) || (i == n))
            cap = INF;
        NewEdges.push_back({i, i+n, 0, cap});
        NewG[i].push_back(NewEdges.size()-1);
        NewEdges.push_back({i+n, i, 0, 0});
        NewG[i+n].push_back(NewEdges.size()-1);
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
        for (int i: NewG[u]) {
            Edge e = NewEdges[i];
            int v = e.v;
            if ((level[v] != -1) || (e.flow >= e.cap))
                continue;
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    return (level[t] != -1);
}

int DFSNewFlow(int u, int t, int PushedVal) {
    if (PushedVal == 0)
        return 0;
    if (u == t)
        return PushedVal;
    for (int &i = iter[u]; i<NewG[u].size(); i++) {
        int id = NewG[u][i];
        Edge e = NewEdges[id];
        int v = e.v;
        if ((level[v] != level[u] + 1) || (e.cap <= e.flow))
            continue;
        int f = min(PushedVal, e.cap - e.flow);
        f = DFSNewFlow(v, t, f);
        if (f == 0)
            continue;
        NewEdges[id].flow += f;
        NewEdges[id^1].flow -= f;
        return f;
    }
    return 0;
}

int MinCut(int s, int t) {
    int NewFlow, MaxFlow = 0;
    while (BFSLevel(s, t)) {
        memset(iter, 0, sizeof(iter));
        while (NewFlow = DFSNewFlow(s, t, INF))
            MaxFlow += NewFlow;
    }
    return MaxFlow;
}

void Solve() {
    while ((cin >> n >> m >> k) && ((n != 0) || (m != 0) || (k != 0))) {
        Init();
        ReadData();
        MakeG();
        cout << MinCut(1, 2*n) << '\n';
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
