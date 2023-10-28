#include <iostream>
#include <bits/stdc++.h>
#define INF 10000000000000001
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
struct Edge {
    int u,v;
    ll w;
};
int n, m, k, deg[MaxN+1];
ll dist[MaxN+1];
vector<pil> graph[MaxN+1], RailWay;
vector<Edge> edges;

void ReadData() {
    int u,v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(pil(v,w));
        graph[v].push_back(pil(u,w));
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    int s, y;
    for (int i=1; i<=k; i++) {
        cin >> s >> y;
        graph[1].push_back(pil(s, y));
        graph[s].push_back(pil(1, y));
        RailWay.push_back({s,y});
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        dist[i] = INF;
}

void Dijkstra(int src) {
    Init();
    set<pil> setds;
    setds.insert(pil(0, src));
    dist[src] = 0;
    while (!setds.empty()) {
        pil tmp = (*setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        for (auto tmpv: graph[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (dist[v] > dist[u] + w) {
                if (setds.find(pil(dist[v], v)) != setds.end())
                    setds.erase(setds.find(pil(dist[v], v)));
                dist[v] = dist[u] + w;
                setds.insert(pil(dist[v], v));
            }
        }
    }
}

int Solution() {
    int ans = 0;
    for (Edge tmp: edges) {
        int u = tmp.u, v = tmp.v;
        ll w = tmp.w;
        if (dist[u] + w == dist[v])
            deg[v]++;
    }
    for (auto tmp: RailWay) {
        int v = tmp.first;
        ll w = tmp.second;
        if (w == dist[v]) {
            if (deg[v] >= 1)
                ans++;
            else
                deg[v]++;
            continue;
        }
        ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    Dijkstra(1);
    cout << Solution();
    return 0;
}
