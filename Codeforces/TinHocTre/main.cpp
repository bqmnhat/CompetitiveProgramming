#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxMask 32
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii; // .first = dist; .second.first = u; .second.second = CurMask;
struct Edge {
    int v;
    ll x, y;
};
int n, m, k, NodeMask[MaxN+5];
ll dp[MaxN+5][MaxMask+5];
vector<Edge> g[MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        g[u].push_back({v, x, y});
        g[v].push_back({u, x, y});
    }
    for (int i=0; i<k; i++) {
        int t;
        cin >> t;
        NodeMask[t] |= (1 << i);
    }
}

ll Solution() {
    for (int i=1; i<=n; i++)
        for (int mask = 0; mask < (1 << k); mask++)
            dp[i][mask] = 1e16;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dp[1][0] = 0;
    pq.push(piii(dp[1][0], pii(1, 0)));
    while (!pq.empty()) {
        ll CurDist = pq.top().first;
        int u = pq.top().second.first, CurMask = pq.top().second.second;
        pq.pop();
        if (CurDist > dp[u][CurMask])
            continue;
        for (Edge e: g[u]) {
            int v = e.v, NxtMask = (CurMask | NodeMask[v]);
            ll NumOfPeople = 2 + __builtin_popcount(CurMask);
            ll CurCost = (e.x + e.y*NumOfPeople);
            if (dp[v][NxtMask] > dp[u][CurMask] + CurCost) {
                dp[v][NxtMask] = dp[u][CurMask] + CurCost;
                pq.push(piii(dp[v][NxtMask], pii(v, NxtMask)));
            }
        }
    }
    return dp[n][(1 << k) - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    cout << Solution();
    return 0;
}
