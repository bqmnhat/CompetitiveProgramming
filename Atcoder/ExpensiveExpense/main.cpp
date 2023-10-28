#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, D[200001];
vector<pll> graph[200001];

void ReadData() {
    int a, b, c;
    for (int i=1; i<n; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(pll(b, c));
        graph[b].push_back(pll(a, c));
    }
    for (int i=1; i<=n; i++)
        cin >> D[i];
}

vector<ll> Dijkstra(int src) {
    vector<ll> dist(n+1, 1e18);
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(pll(0, src));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto tmpv: graph[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pll(dist[v], v));
            }
        }
    }
    return dist;
}

void Solve() {
    int root = 1, s = -1, t = -1;
    vector<ll> droot;
    droot = Dijkstra(root);
    ll MaxCost = 0;
    for (int i = 2; i<=n; i++) {
        if (D[i] + droot[i] > MaxCost) {
            MaxCost = D[i] + droot[i];
            s = i;
        }
    }
    MaxCost = 0;
    vector<ll> ds = Dijkstra(s);
    for (int i=1; i<=n; i++) {
        if (i == s)
            continue;
        if (D[i] + ds[i] > MaxCost) {
            MaxCost = D[i] + ds[i];
            t = i;
        }
    }
    vector<ll> dt = Dijkstra(t);
    for (int i=1; i<=n; i++) {
        ll ans = -1;
        if (i != s)
            ans = max(ans, (ds[i] + D[s]));
        if (i != t)
            ans = max(ans, (dt[i] + D[t]));
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
