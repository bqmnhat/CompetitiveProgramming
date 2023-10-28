#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m, d[MaxN+1];
vector<pll> g[MaxN+1];
const ll inf = 1e9 + 7;

void ReadGraph() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pll(v, w));
        g[v].push_back(pll(u, w));
    }
}

ll Dijkstra(int src, int des, ll val) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i=1; i<=n; i++)
        d[i] = inf;
    pq.push(pll(0LL, src));
    d[src] = 0LL;
    while (!pq.empty()) {
        pll tmpu = pq.top();
        pq.pop();
        int u = tmpu.second;
        if (tmpu.first > d[u])
            continue;
        if (u == des)
            return d[u];
        for (pll tmpv: g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (w > val)
                w = 1LL;
            else
                w = 0LL;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(pll(d[v], v));
            }
        }
    }
    return -1;
}

ll Solution() {
    ll lo = 0, hi = inf, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        ll tmp = Dijkstra(1, n, mid);
        if (tmp == -1)
            return -1;
        if (tmp <= 1) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    cout << Solution();
    return 0;
}
