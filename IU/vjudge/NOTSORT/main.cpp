#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, dist[MaxN+1];
vector<int> graph[MaxN+1];
bool vis[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int BFS(int src, int des) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == des)
            return (dist[u] - 1);
        for (int v: graph[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    cout << BFS(1, n);
    return 0;
}
