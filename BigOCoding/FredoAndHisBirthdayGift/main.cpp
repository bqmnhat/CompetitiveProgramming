#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n, m, MaxDist[11];
vector<int> graph[11];
bool vis[11];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void Init() {
    for (int i=1; i<=10; i++) {
        vis[i] = false;
        graph[i].clear();
        MaxDist[i] = 0;
    }
}

void Hamilton(int u, int dist) {
    MaxDist[u] = max(MaxDist[u], dist);
    for (auto v: graph[u]) {
        if (!vis[v]) {
            vis[v] = true;
            Hamilton(v, dist+1);
            vis[v] = false;
        }
    }
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        for (int st=1; st<=n; st++) {
            vis[st] = true;
            Hamilton(st,0);
            vis[st] = false;
        }
        for (int i=1; i<=n; i++)
            cout << MaxDist[i] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    return 0;
}
