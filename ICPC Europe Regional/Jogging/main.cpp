#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef pair<int, int> pii;
struct Edge {
    int u,v,w;
};
vector<pii> g[100001];
vector<Edge> edges;
int n, m, L, U;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
        edges.push_back({u,v,w});
    }
}

void Dijkstra(int st, vector<int> &dist) {
    set<pii> setds;
    setds.insert(pii(0LL, st));
    dist[st] = 0LL;
    while (!setds.empty()) {
        pii tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u  = tmp.second;
        for (auto i: g[u]) {
            int v = i.first, wei = i.second;
            if (dist[v] > dist[u] + wei) {
                if (dist[v] != INF)
                    setds.erase(setds.find(pii(dist[v], v)));
                dist[v] = dist[u] + wei;
                setds.insert(pii(dist[v], v));
            }
        }
    }
}

int Solution() {
    vector<int> dist(n, INF);
    Dijkstra(0, dist);
    int ans = 0;
    for (auto i : edges)
        if ((dist[i.u] <= (U-1)/2) || (dist[i.v] <= (U-1)/2))
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> L >> U;
    ReadData();
    cout << Solution();
    return 0;
}

