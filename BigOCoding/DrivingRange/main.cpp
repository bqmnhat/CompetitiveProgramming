#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef pair<int, int> pii;
int n, m, dist[10000001];
vector<pii> graph[10000001];
bool vis[10000001];

void ReadGraph() {
    for (int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
    }
}

void Init() {
    for (int i=0; i<=n; i++) {
        dist[i] = INF;
        graph[i].clear();
        vis[i] = false;
    }
}

void Solve() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));
    dist[0] = 0;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (vis[u])
            continue;
        vis[u] = true;
        for (pii i : graph[u]) {
            int w = i.second, v = i.first;
            if ((!vis[v]) && (dist[v] > w)) {
                dist[v] = w;
                pq.push(pii(dist[v], v));
            }
        }
    }
    int Max = -1;
    for (int i=0; i<n; i++) {
        if (dist[i] != INF)
            Max = max(Max, dist[i]);
    }
    if (Max <= 0)
        cout << "IMPOSSIBLE";
    else
        cout << Max;
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while ((n != 0) || (m != 0)) {
        Init();
        ReadGraph();
        Solve();
        cin >> n >> m;
    }
    return 0;
}
