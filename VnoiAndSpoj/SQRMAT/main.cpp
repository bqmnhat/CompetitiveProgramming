#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
int n, m, vis[MaxN+1], dist[MaxN+1];
vector<int> g[MaxN+1], RevG[MaxN+1], TopoOrder;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        RevG[v].push_back(u);
    }
}

bool DFSCheckCycle(int u) {
    vis[u] = 1;
    bool IsCycle = false;
    for (int v: g[u]) {
        if (vis[v] == 1)
            return true;
        else if (vis[v] == 0)
            IsCycle |= DFSCheckCycle(v);
    }
    vis[u] = 2;
    return IsCycle;
}

void TopoDFS(int u) {
    vis[u] = 1;
    for (int v: g[u])
        if (vis[v] == 0)
            TopoDFS(v);
    TopoOrder.push_back(u);
}

void DFSMaxDist(int u) {
    if (dist[u] != -1)
        return;
    dist[u] = 0;
    for (int v: RevG[u]) {
        DFSMaxDist(v);
        dist[u] = max(dist[v] + 1, dist[u]);
    }
}

int Solution() {
    for (int i=1; i<=n; i++)
        if (DFSCheckCycle(i))
            return -1;
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++)
        if (vis[i] == 0)
            TopoDFS(i);
    reverse(TopoOrder.begin(), TopoOrder.end());
    for (int i=1; i<=n; i++)
        dist[i] = -1;
    int ans = 0;
    for (int u: TopoOrder) {
        DFSMaxDist(u);
        ans = max(ans, dist[u]);
    }
    return (ans+1);
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
