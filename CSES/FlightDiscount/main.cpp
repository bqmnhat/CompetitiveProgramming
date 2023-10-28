#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> piii;
const ll INF = 1e15 + 7;
ll dist[MaxN+5][5];
int n, m;
vector<pii> g[MaxN+5];

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
    }
}

void Init() {
    for (int i=0; i<=n; i++)
        for (int j=0; j<=2; j++)
            dist[i][j] = INF;
}

void Dijkstra(int src) {
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push(piii(pii(0LL, 0LL), src));
    dist[src][0] = 0;
    while (!pq.empty()) {
        piii tmp = pq.top();
        pq.pop();
        int u = tmp.second, d = tmp.first.first, k = tmp.first.second;
        if (d > dist[u][k])
            continue;
        for (pii tmp: g[u]) {
            int v = tmp.first;
            ll w = tmp.second;
            if (k == 0) {
                if (dist[v][k+1] > dist[u][k] + (w/2LL)) {
                    dist[v][k+1] = dist[u][k] + (w/2LL);
                    pq.push(piii(pii(dist[v][k+1], k+1), v));
                }
            }
            if (dist[v][k] > dist[u][k] + w) {
                dist[v][k] = dist[u][k] + w;
                pq.push(piii(pii(dist[v][k], k), v));
            }
        }
    }
}

ll Solution() {
    Init();
    Dijkstra(1);
    ll ans = min(dist[n][0], dist[n][1]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
