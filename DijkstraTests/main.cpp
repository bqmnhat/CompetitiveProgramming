#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m;
ll dist[MaxN+1];
vector<pii> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

ll Dijkstra(int src, int des) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second, du = tmp.first;
        if (du > dist[u])
            continue;
        for (pii tmpv: g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
    return dist[des];
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
