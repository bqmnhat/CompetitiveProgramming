#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m, k;
vector<pii> g[MaxN+1];
priority_queue<pii, vector<pii>, greater<pii>> pq;
ll dist[MaxN+1];
const ll INF = 1e18;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(pii(v, 1));
        g[v].push_back(pii(u, 1));
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        ll t;
        int u, v;
        cin >> t >> u >> v;
        g[u].push_back(pii(v, t));
        g[v].push_back(pii(u, t));
    }
}

ll Dijkstra(int s, int t) {
    for (int i=1; i<=n; i++)
        dist[i] = INF;
    pq.push(pii(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du > dist[u])
            continue;
        for (pii tmpv: g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second, RealW;
            if (w != 1)
                RealW = max(1LL, w - du);
            else
                RealW = w;
            if (dist[v] > dist[u] + RealW) {
                dist[v] = dist[u] + RealW;
                pq.push(pii(dist[v], v));
            }
        }
    }
    return dist[t];
}

ll Solution() {
    ll ans = Dijkstra(1, n);
    if (ans >= INF)
        return -1;
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
