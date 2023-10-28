#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll dpDown[MaxN+5], dpUp[MaxN+5], ans[MaxN+5], sz[MaxN+5];
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
    dpDown[u] = sz[u] = 0;
    for (int v: g[u]) {
        if (v != p) {
            DFSDown(v, u);
            dpDown[u] += dpDown[v];
            sz[u] += sz[v];
        }
    }
    dpDown[u] += sz[u];
    sz[u]++;
}

void DFSUp(int u, int p) {
    dpUp[u] = 0;
    if (p != -1)
        dpUp[u] = dpUp[p] + (dpDown[p] - sz[u] - dpDown[u]) + (n*1LL - sz[u]);
    ans[u] = dpDown[u] + dpUp[u];
    for (int v: g[u])
        if (v!=p)
            DFSUp(v, u);
}

void Solve() {
    DFSDown(1, -1);
    DFSUp(1, -1);
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
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
