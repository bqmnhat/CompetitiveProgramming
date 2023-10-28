#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, t;
bool vis[MaxN+1];
vector<int> g[MaxN+1];

void Init() {
    for (int i=0; i<n; i++) {
        vis[i] = false;
        g[i].clear();
    }
}

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u) {
    vis[u] = true;
    for (auto v: g[u])
        if (!vis[v])
            DFS(v);
}

int Solution() {
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            ans++;
            DFS(i);
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<= t; i++) {
        cin >> n >> m;
        Init();
        ReadGraph();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
