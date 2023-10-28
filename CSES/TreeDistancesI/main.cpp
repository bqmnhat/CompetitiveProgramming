#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, dpDown[MaxN+5], dpUp[MaxN+5], AnsDist[MaxN+5];
vector<int> g[MaxN+5];
vector<pii> dist[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSDown(int u, int p) {
    dpDown[u] = 0;
    for (int v: g[u]) {
        if (v != p) {
            DFSDown(v, u);
            dist[u].push_back(pii(dpDown[v], v));
        }
    }
    if (dist[u].size() > 0) {
        sort(dist[u].begin(), dist[u].end(), greater<pii>());
        dpDown[u] = dist[u][0].first+1;
    }
}

void DFSUp(int u, int p) {
    dpUp[u] = 0;
    if (p != -1) {
        dpUp[u] = dpUp[p] + 1;
        if (dist[p].size() > 0) {
            if (dist[p][0].second != u)
                dpUp[u] = max(dpUp[u], dist[p][0].first + 2);
            else if (dist[p].size() >= 2)
                dpUp[u] = max(dpUp[u], dist[p][1].first + 2);
        }
    }
    AnsDist[u] = max(dpDown[u], dpUp[u]);
    for (int v: g[u])
        if (v != p)
            DFSUp(v, u);
}

void Solve() {
    DFSDown(1, -1);
    DFSUp(1, -1);
    for (int i=1; i<=n; i++)
        cout << AnsDist[i] << ' ';
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
