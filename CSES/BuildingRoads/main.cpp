#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m;
bool vis[MaxN+1];
vector<int> g[MaxN+1], Rep;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u) {
    for (int v: g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            DFS(v);
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            Rep.push_back(i);
            vis[i] = true;
            DFS(i);
        }
    }
    cout << Rep.size() - 1 << '\n';
    if (Rep.size() > 1)
        for (int i=1; i<Rep.size(); i++)
            cout << Rep[i-1] << ' ' << Rep[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
