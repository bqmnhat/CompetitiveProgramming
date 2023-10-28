#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e14 + 7;
int n, m;
vector<pii> g[MaxN+5];
ll dist[MaxN+5];

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
    }
}

void Djikstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0LL, src));
    vector<ll> dist(n+1, INF);
    dist[src] = 0LL;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        ll d = tmp.first;
        if (d > dist[u])
            continue;
        for (pii e: g[u]) {
            int v = e.first;
            ll w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
    for (int i=1; i<=n; i++)
        cout << dist[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Djikstra(1);
    return 0;
}
