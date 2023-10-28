#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
struct Edge {
    int u, v;
    ll c;
};
int n, par[MaxN+1];
ll dist[MaxN+1][2], s, MaxDistToOthers[MaxN+1]; // dist[u][0] = Down[u], dist[u][1] = Up[u]
vector<pii> g[MaxN+1], d[MaxN+1];
vector<Edge> edges;

void ReadData() {
    int u, v;
    ll c;
    for (int i=1; i<n; i++) {
        cin >> u >> v >> c;
        g[u].push_back(pii(v, c));
        g[v].push_back(pii(u, c));
        edges.push_back({u, v, c});
    }
}

void DFSDown(int u, int p) {
    dist[u][0] = 0;
    par[u] = p;
    ll MaxVal = 0;
    for (pii tmpv: g[u]) {
        int v = tmpv.first;
        ll w = tmpv.second;
        if (v == p)
            continue;
        DFSDown(v, u);
        d[u].push_back(pii(dist[v][0] + w, v));
        MaxVal = max(MaxVal, dist[v][0] + w);
    }
    dist[u][0] = MaxVal;
    if (d[u].size() > 0)
        sort(d[u].begin(), d[u].end(), greater<pii>());
}

void DFSUp(int u, int p, ll PrevW) {
    dist[u][1] = 0;
    if (p != -1) {
        dist[u][1] = dist[p][1] + PrevW;
        if (d[p].size() > 0) {
            if (u != d[p][0].second)
                dist[u][1] = max(dist[u][1], d[p][0].first + PrevW);
            else if (d[p].size() >= 2)
                dist[u][1] = max(dist[u][1], d[p][1].first + PrevW);
        }
    }
    MaxDistToOthers[u] = max(dist[u][0], dist[u][1]);
    for (pii tmpv: g[u]) {
        int v = tmpv.first;
        ll w = tmpv.second;
        if (v!=p)
            DFSUp(v, u, w);
    }
}

ll Solution() {
    DFSDown(1, -1);
    DFSUp(1, -1, 0);
    ll ans = 1e18;
    for (int i=1; i<=n; i++)
        ans = min(ans, MaxDistToOthers[i]);
    for (int i=0; i<n-1; i++) {
        ll c = edges[i].c;
        if (c <= s) {
            int u = edges[i].u, v = edges[i].v, p, child;
            if (par[u] == v) {
                p = v;
                child = u;
            }
            else {
                p = u;
                child = v;
            }
            ll tmp = max(dist[p][1], dist[child][0]);
            if (d[p].size() > 0) {
                if (child != d[p][0].second)
                    tmp = max(tmp, d[p][0].first);
                else if (d[p].size() >= 2)
                    tmp = max(tmp, d[p][1].first);
            }
            ans = min(ans, tmp);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SERVICE.INP", "r", stdin);
    freopen("SERVICE.OUT", "w", stdout);
    cin >> n >> s;
    ReadData();
    cout << Solution();
    return 0;
}
