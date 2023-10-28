#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m;
bool vis[MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
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

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            DFS(i);
            ans++;
        }
    }
    return ans;
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
