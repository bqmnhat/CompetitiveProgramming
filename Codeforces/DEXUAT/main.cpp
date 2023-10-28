#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxM 100000
#define MaxK 300
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> p3i;
const ll INF = 1e18;
int n, m, k, s, t;
vector<pii> g[MaxM+5], RevG[MaxM+5];
ll dist[MaxN+5], RevDist[MaxN+5];
vector<p3i> RecEdges;

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        RevG[v].push_back(pii(u, w));
    }
    for (int i=1; i<=k; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        RecEdges.push_back(p3i(w, pii(u, v)));
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        dist[i] = RevDist[i] = INF;
}

void Dijkstra(int src, const vector<pii> g[MaxN+5], ll dist[MaxN+5]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push(pii(0, src));
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
}

ll Solution() {
    Init();
    Dijkstra(s, g, dist);
    Dijkstra(t, RevG, RevDist);
    ll ans = dist[t];
    for (p3i e: RecEdges) {
        ll w = e.first;
        int u = e.second.first, v = e.second.second;
        ans = min(ans, dist[u] + w + RevDist[v]);
        ans = min(ans, dist[v] + w + RevDist[u]);
    }
    if (ans >= INF)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s >> t;
    ReadData();
    cout << Solution();
    return 0;
}
