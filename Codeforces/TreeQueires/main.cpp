#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, m, k, v[MaxN+1], tIn[MaxN+1], tOut[MaxN+1], par[MaxN+1], depth[MaxN+1], cnt;
vector<int> graph[MaxN+1];
bool vis[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void ReadData() {
    for (int i=1; i<=k; i++)
        cin >> v[i];
}

void DFS(int u, int p, int d) {
    vis[u] = true;
    par[u] = p;
    depth[u] = d;
    cnt++;
    tIn[u] = cnt;
    for (auto v: graph[u])
        if (!vis[v])
            DFS(v, u, d+1);
    cnt++;
    tOut[u] = cnt;
}

bool IsAncestor(int u, int v) {
    return ((tIn[u] <= tIn[v]) && (tIn[v] <= tOut[u]));
}

void Solve() {
    DFS(1, -1, 0);
    for (int i=1; i<=m; i++) {
        cin >> k;
        ReadData();
        cnt = 0;
        int DeepestNode = v[1];
        for (int i=2; i<=k; i++)
            if (depth[DeepestNode] < depth[v[i]])
                DeepestNode = v[i];
        for (int i=1; i<=k; i++) {
            if ((v[i] == DeepestNode) || (v[i] == 1))
                continue;
            v[i] = par[v[i]];
        }
        bool IsInPath = true;
        for (int i=1; i<=k; i++)
            IsInPath = (IsInPath & IsAncestor(v[i], DeepestNode));
        if (IsInPath)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    Solve();
    return 0;
}
